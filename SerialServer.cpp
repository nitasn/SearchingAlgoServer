//
// Created by Nitsan BenHanoch on 29/01/2020.
//

#include "SerialServer.h"

using namespace std;


namespace server_side
{
    void SerialServer::on_client_connect(int client_socket)
    {
        // a serial manner...
        communicate_with_client(this, client_socket);
    }
}