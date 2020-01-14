//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_SERVER_SIDE_H
#define SEARCHINGALGOSERVER_SERVER_SIDE_H

#include <iostream>
#include <netinet/in.h>
#include <thread>
#include <sys/socket.h>

namespace server_side
{
    struct ClientHandler
    {
        virtual void handle(std::istream &inStreamToHandle, std::ostream &outStreamToHandle) = 0;
    };

    struct Server
    {
        //todo this need be hear? or not?
        class notSeccsedOpenSocket: public std::exception{};
        class notSeccsedBindSocket: public std::exception{};
        class notSeccsedListenToClient: public std::exception{};
        class notSeccsedAcceptingClient: public std::exception{};
        int socketfd;
        int client_socket;
        bool should_stop = false;
        server_side::ClientHandler *clientHandler;
        std::thread *serverThread = nullptr;
        virtual void start(int port, ClientHandler *clientHandler) = 0;
        virtual void stop() = 0;
        void connectToClient(int port, int max_connected){
            this->socketfd = socket(AF_INET, SOCK_STREAM, 0);
            if (socketfd == -1) {
                throw (notSeccsedOpenSocket());
            }
            sockaddr_in address;
            address.sin_family = AF_INET;
            address.sin_addr.s_addr = INADDR_ANY;
            address.sin_port = htons(port);
            //todo problem or nothing?
            if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1){
                throw notSeccsedBindSocket();
            }
            if (listen(socketfd, max_connected) == -1) {
                throw notSeccsedListenToClient();
            } else{
                std::cout<<"Server is now listening ..."<<std::endl;
            }
            client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
            if (client_socket == -1) {
                throw notSeccsedAcceptingClient();
            }
        }
    };
}

#endif //SEARCHINGALGOSERVER_SERVER_SIDE_H
