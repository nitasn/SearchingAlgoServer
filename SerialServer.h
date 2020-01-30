//
// Created by Nitsan BenHanoch on 29/01/2020.
//

#ifndef SERVER_TEST_SERIALSERVER_H
#define SERVER_TEST_SERIALSERVER_H

#include "BaseServer.h"

namespace server_side
{
    class SerialServer : public BaseServer
    {
    public:
        SerialServer(int port, ClientHandler *clientHandler) : BaseServer(port, clientHandler) {}

    protected:
        void on_client_connect(int client_socket) override;
    };

}
#endif //SERVER_TEST_SERIALSERVER_H
