//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_MYSERIALSERVER_H
#define SEARCHINGALGOSERVER_MYSERIALSERVER_H

#include <server_side.h>
#include <sys/socket.h>

namespace server_side
{
    struct MySerialServer : public Server
    {
        void start(int port, ClientHandler *clientHandler) override;
        void stop() override ;
        ~MySerialServer();
    };

    class MyParallelServer : Server
    {
        // later
    };
}

#endif //SEARCHINGALGOSERVER_MYSERIALSERVER_H
