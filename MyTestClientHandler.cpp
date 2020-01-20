//
// Created by hodyah on 20.1.2020.
//
#include <MyTestClientHandler.h>
using namespace std;
MyTestClientHandler::MyTestClientHandler(Solver<std::string,std::string> *solverProblem, int port){
    this->solverProblem = solverProblem;
    this->port = port;
}

void MyTestClientHandler::handle(vector<string> vectorString){
    this->anser = this->solverProblem->solve(vectorString);
    sendAnserToClient();
}
void MyTestClientHandler::sendAnserToClient(){
    server_side::ClientHandler::connectToClient(this->port);
    for ( vector<string>::iterator it = this->anser->begin(); it != anser->end(); it++){
        if (send(client_socket, it->c_str(), it->length(), 0) == -1){
            throw notSeccsedSendToClient();
        }
    }
}