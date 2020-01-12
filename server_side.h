//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_SERVER_SIDE_H
#define SEARCHINGALGOSERVER_SERVER_SIDE_H

#include <iostream>

namespace server_side
{

    struct ClientHandler
    {
        virtual void handle(std::istream &in, std::ostream &out) = 0;
    };

    struct Server
    {
        virtual void start(int port, ClientHandler *clientHandler) = 0;

        virtual void stop() = 0;
    };
}

#endif //SEARCHINGALGOSERVER_SERVER_SIDE_H
