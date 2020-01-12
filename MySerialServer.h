//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_MYSERIALSERVER_H
#define SEARCHINGALGOSERVER_MYSERIALSERVER_H

#include <server_side.h>

namespace server_side
{
    class MySerialServer : Server
    {
        void start(int port, ClientHandler *clientHandler) override;

        void stop() override ;
    };

    class MyParallelServer : Server
    {
        // later
    };
}

#endif //SEARCHINGALGOSERVER_MYSERIALSERVER_H
