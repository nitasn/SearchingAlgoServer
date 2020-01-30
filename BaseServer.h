//
// Created by Nitsan BenHanoch on 29/01/2020.
//

#ifndef SERVER_TEST_BASESERVER_H
#define SERVER_TEST_BASESERVER_H

#include <thread>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ostream>
#include "ClientHandler.h"


namespace server_side
{
    const int BUFFER_SIZE = 1024;

    class BaseServer
    {
        const static int MAX_CONNECTIONS = 10;

        int port, socket_fd{};
        sockaddr_in address{};

        std::thread *accepting_clients_thread = nullptr;
        bool should_stop_accepting_clients = false;

        /// wait for clients and call 'on_client_connect' when a client connects
        static void accept_clients(BaseServer *self);

        /// has a function that returns an answer string for a question string
        ClientHandler *clientHandler;

    protected:

        /// call 'read_from_client'; in a dedicated thread to be parallel, or on same thread to be serial
        virtual void on_client_connect(int client_socket) = 0;

        /// for the use of SerialServer and ParallelServer who implement us
        static void communicate_with_client(BaseServer *self, int client_socket);

    public:

        /// listen on port and start accepting clients
        BaseServer(int port, ClientHandler *clientHandler); // "start"

        /// stop accepting clients and stop listening on port
        virtual ~BaseServer(); // "stop"
    };

    class AcceptingClientFailed : std::exception {};

    class CouldNotBindSocketToIP : std::exception {};

    class CouldNotCreateSocket : std::exception {};

    class CouldNotStartListening : std::exception {};
}

#endif //SERVER_TEST_BASESERVER_H
