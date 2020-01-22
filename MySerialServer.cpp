//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#include "MySerialServer.h"

//todo when need be timeout?
using namespace std;

void server_side::serverListenLoop(server_side::Server* self){
    //todo when this stop?
    while (!self->should_stop){
        if (listen(self->socketfd, MAX_CONNECTIONS == -1)) { // todo should listen be outside the loop?
            throw notSeccsedListenToClient();
        } else{
            std::cout<<"Server is now listening ..."<<std::endl;
        }
        self->client_socket = accept(self->socketfd, (struct sockaddr *) &self->address,
                                     (socklen_t *) &self->address);
        if (self->client_socket == -1) {
            throw notSeccsedAcceptingClient();
        }
//        while (true){
        char buffer[SIZE_BUFFER] = {"start"};
        //todo check what id the assigmnet
        const char *endLisenLinux = "end\r\n";
        const char *endLisenNotLinux = "end\n";
        std::vector<std::string> vectorInputStram;
//        istringstream inStream(string(buffer,SIZE_BUFFER));
        //todo this is good? can be end in begging? this is the end?
        while(strcmp(endLisenLinux, buffer) != 0 && strcmp(endLisenNotLinux, buffer) != 0){
            int msg_size = read(self->client_socket , &buffer, SIZE_BUFFER);
            std::string data(buffer, msg_size);
            vectorInputStram.push_back(data);
        }
        class notSeccsedSendToClient: public std::exception{};
        auto sendOver = [&](std::string &str)
        {
            if (send(self->client_socket, str.c_str(), str.length(), 0) == -1){
                throw notSeccsedSendToClient();
            }
        };
        self->clientHandler->handle(vectorInputStram, sendOver);
    }
}

void server_side::MySerialServer::stop(){
    this->should_stop = true;
    this->serverThread->join();
    delete(this->serverThread);
    cout << "I stop" << endl;
    close(this->socketfd); // closing the listening socket
    close(this->client_socket);
}

server_side::MySerialServer::~MySerialServer(){
    stop();
    cout << "I delete" << endl;
}

void server_side::MySerialServer::start(int port, server_side::ClientHandler *clientHandler) {
    server_side::Server::playThePort(port, clientHandler);
    this->serverThread = new thread(server_side::serverListenLoop, this);
}


