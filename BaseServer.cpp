//
// Created by Nitsan BenHanoch on 29/01/2020.
//

#include "BaseServer.h"
#include "log_info.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include "ClientHandler.h"
#include <unistd.h>
#include <sstream>

using namespace std;


bool str_ends_with(string const &fullString, string const &ending)
{
    if (fullString.length() < ending.length())
        return false;

    return fullString.compare(fullString.length() - ending.length(), ending.length(), ending) == 0;
}


/**
 * make sure new lines symbols are \r\n and not just \n or \r
 * @example "abc \r xyz \r\n 1234 \n blah" -> "abc \r\n xyz \r\n 1234 \r\n blah"
 */
string fix_new_lines_symbols(const string& str)
{
    stringstream builder;

    char last_char = '\0';

    for (char letter : str)
    {
        if (letter == '\n')
        {
            if (last_char != '\r')
                builder << '\r';
        }
        else
        {
            if (last_char == '\r')
                builder << '\n';
        }
        builder << letter;
        last_char = letter;
    }

    return builder.str();
}

namespace server_side
{
    BaseServer::BaseServer(int port, ClientHandler *clientHandler) : port(port), clientHandler(clientHandler)
    {
        this->socket_fd = socket(AF_INET, SOCK_STREAM, 0);

        if (this->socket_fd == -1) {
            cerr << "Could not create a socket" << endl;
            throw CouldNotCreateSocket();
        }

        this->address.sin_family = AF_INET;
        this->address.sin_addr.s_addr = INADDR_ANY;
        this->address.sin_port = htons(this->port);


        // todo setsockopt() no blocking

        if (::bind(this->socket_fd, (struct sockaddr *) &this->address, sizeof(this->address)) == -1)
        {
            cerr << "Could not bind the socket to an IP" << endl;
            throw CouldNotBindSocketToIP();
        }
        if (listen(this->socket_fd, MAX_CONNECTIONS) == -1)
        {
            cerr << "Error during listening command" << endl;
            throw CouldNotStartListening();
        }

        log_info << "server is now listening..." << endl;

        this->accepting_clients_thread = new thread(accept_clients, this);
    }

    void BaseServer::accept_clients(BaseServer *self)
    {
        while (!self->should_stop_accepting_clients)
        {
            // todo how to set a timeout?
            int c_socket = accept(self->socket_fd, (struct sockaddr *) &self->address, (socklen_t *) &self->address);

            // waiting here until a client connects

            if (c_socket == -1)
            {
                cerr << "server: error accepting client" << endl;
                throw AcceptingClientFailed();
            }

            // 'should_stop_accepting_clients' would be changed from a different thread by calling our destructor
            if (self->should_stop_accepting_clients)
            {
                log_info << "closing c_socket just after client connected because should_stop_accepting_clients" << endl;
                close(c_socket);
                return;
            }

            log_info << "server accepted client" << endl;

            self->on_client_connect(c_socket);
        }
    }

    BaseServer::~BaseServer()
    {
        should_stop_accepting_clients = true;
        accepting_clients_thread->join();
        delete accepting_clients_thread;

        log_info << "closing socket_fd" << endl;
        close(socket_fd);
    }

    void BaseServer::communicate_with_client(BaseServer *self, int client_socket)
    {
        string ENDING = "end\r\n"; // according to protocol, question's end will be marked with the string ENDING

        char buffer[server_side::BUFFER_SIZE];

        string msg_to_client;

        bool msg_received_ok;

        while (true)
        {
            int msg_length = read(client_socket, buffer, sizeof(buffer)); // todo give timeout

            if (msg_length <= 0)
            {
                msg_received_ok = false;
                break;
            }

            msg_to_client += string(buffer, msg_length); // todo that's O(buffer) instead of O(1)... fix later
                                                         //  currently needed to check if msg ended with ENDING
                                                         //  cause it might split into more than one buffers...

            msg_to_client = fix_new_lines_symbols(msg_to_client); // yes, that does make it O(n^2). it's an awful hack

            if (str_ends_with(msg_to_client, ENDING))
            {
                msg_to_client = msg_to_client.substr(0, msg_to_client.size() - ENDING.size());
                msg_received_ok = true;
                break;
            }
        }

        if (msg_received_ok)
        {
            string response = self->clientHandler->handle_client(msg_to_client);

            send(client_socket, response.c_str(), (int) response.size(), 0);

            log_info << "data transfer with client ended successfully" << endl;
        }
        else
        {
            log_info << "client disconnected... did not transfer data" << endl;
        }

        log_info << "closing client_socket" << endl;
        close(client_socket);
    }
}