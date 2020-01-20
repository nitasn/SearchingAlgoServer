//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_MYSERIALSERVER_H
#define SEARCHINGALGOSERVER_MYSERIALSERVER_H
const int MAX_CONNECTIONS = 1;
const int SIZE_BUFFER = 1024;
#include <thread>
#include <iostream>
#include <sys/socket.h>
#include <server_side.h>
namespace server_side
{
    static void serverListenLoop(server_side::Server* self);

    struct MySerialServer : public Server {
        void stop() override;
        ~MySerialServer();
        void start(int port, ClientHandler *clientHandler)  override ;
    };

    class MyParallelServer : Server
    {
        // later
    };
}

class notSeccsedListenToClient: public std::exception{};
class notSeccsedAcceptingClient: public std::exception{};

#endif //SEARCHINGALGOSERVER_MYSERIALSERVER_H
