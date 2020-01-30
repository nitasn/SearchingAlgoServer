//
// Created by Nitsan BenHanoch on 29/01/2020.
//

#include "ParallelServer.h"

using namespace std;

namespace server_side
{
    void ParallelServer::on_client_connect(int client_socket)
    {
        thread client_thread(communicate_with_client, this, client_socket);
        client_thread.detach();
    }
}