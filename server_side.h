//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_SERVER_SIDE_H
#define SEARCHINGALGOSERVER_SERVER_SIDE_H
#include <iostream>
#include <netinet/in.h>
#include <thread>
#include <vector>
#include <sys/socket.h>
#include "string.h"
#include <unistd.h>
#include <fstream>
#include <vector>
#include <arpa/inet.h>
#include <functional>

namespace server_side
{

    struct ClientHandler
    {
//        virtual void handle(std::istream &inStreamToHandle, std::ostream &outStreamToHandle) = 0;
        virtual void handle(std::vector<std::string>,
                std::function<void(std::string&)> send) = 0;
        int client_socket{};
//        virtual void sendAnserToClient() = 0;
        ~ClientHandler()
        {
            close(this->client_socket);
        }
    };
    struct Server
    {
        //todo this need to be in loop? or how this work?
        class notSeccsedSocketClient: public std::exception{};
        class notConnectToHostServer: public std::exception{};
        class notSeccsedOpenSocket: public std::exception{};
        class notSeccsedBindSocket: public std::exception{};
        int socketfd;
        int client_socket;
        sockaddr_in address;
        bool should_stop = false;
//        virtual void playTheThread() = 0;
        server_side::ClientHandler *clientHandler;
        std::thread *serverThread = nullptr;
//        virtual void start(int port, ClientHandler *clientHandler) = 0;
        virtual void stop() = 0;
//        void connectToClient(int port, ClientHandler *clientHandler);
        virtual void start(int port, ClientHandler *clientHandler) =0;
        void playThePort(int port, ClientHandler *clientHandler){
            this->clientHandler = clientHandler;
            this->socketfd = socket(AF_INET, SOCK_STREAM, 0);
            if (socketfd == -1) {
                throw (notSeccsedOpenSocket());
            }
            this->address.sin_family = AF_INET;
            this->address.sin_addr.s_addr = INADDR_ANY;
            this->address.sin_port = htons(port);
            //todo problem or nothing?
            if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1){
                throw notSeccsedBindSocket();
            }
//           connectToClient(port, MAX_CONNECTIONS);
        }
        //todo maybe not need, need check
//        void connectToClient(int port){
//            client_socket = socket(AF_INET, SOCK_STREAM, 0);
//            if (client_socket == -1)
//            {
//                throw notSeccsedSocketClient();
//            }
//            //We need to create a sockaddr obj to hold address of server
//            sockaddr_in address{}; //it means IP4
//            address.sin_family = AF_INET;//IP4
//            address.sin_addr.s_addr = inet_addr("127.0.0.1");  //the localhost address
//            address.sin_port = htons(port);
//            //we need to convert our number (both port & localhost)
//            // to a number that the network understands.
//
//            // Requesting a connection with the server on local host
//            if (connect(client_socket, (struct sockaddr *) &address, sizeof(address)) == -1)
//            {
//                throw notConnectToHostServer();
//            }
//        }
    };
}

#endif //SEARCHINGALGOSERVER_SERVER_SIDE_H
