//
// Created by hodyah on 20.1.2020.
//
#include <MyTestClientHandler.h>
#include <sstream>
using namespace std;
MyTestClientHandler::MyTestClientHandler(Solver<std::string,std::string> *solverProblem){
    this->solverProblem = solverProblem;
}
/**
 * handle the client. send the input from client to solve,
 * and send with function input to client
 * @param vectorString input from client
 * @param send function to send the anser to client
 */
void MyTestClientHandler::handle(vector<string> vectorString, function<void(string&)> send){
//    this->anser = this->solverProblem->solve(vectorString); todo this line
    stringstream answerBuilder;
    for (string &str : vectorString){
        answerBuilder << str << endl;
    }
    string result(answerBuilder.str());
    send(result);
//    sendAnserToClient();
}
//void MyTestClientHandler::sendAnserToClient(){
////    server_side::ClientHandler::connectToClient(this->port);
////
////        if (send(client_socket, it->c_str(), it->length(), 0) == -1){
////            throw notSeccsedSendToClient();
////        }
////    }
////}