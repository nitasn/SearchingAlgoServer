//
// Created by Nitsan BenHanoch on 29/01/2020.
//

#ifndef SERVER_TEST_PARALLELSERVER_H
#define SERVER_TEST_PARALLELSERVER_H

#include <set>
#include "BaseServer.h"
namespace server_side
{
    class ParallelServer : public BaseServer
    {
    public:
        ParallelServer(int port, server_side::ClientHandler *clientHandler) : BaseServer(port, clientHandler) {}

    protected:
        void on_client_connect(int client_socket) override;
    };
}

#endif //SERVER_TEST_PARALLELSERVER_H
