//
// Created by hodyah on 18.1.2020.
//

#ifndef SEARCHINGALGOSERVER_MyTestClientHandler_H
#define SEARCHINGALGOSERVER_MyTestClientHandler_H

#include <server_side.h>
#include <Solver.h>

class MyTestClientHandler: public server_side::ClientHandler{
//    Solver<Problem, Solution> solverProblem;
    Solver<std::string, std::string> *solverProblem;
    int port;
    std::vector<std::string>* theProblem;
    std::vector<std::string>* anser;
    class notSeccsedSendToClient: public std::exception{};
public:
    void sendAnserToClient() override;
    void handle(std::vector<std::string> vectorString) override;
    MyTestClientHandler(Solver<std::string, std::string> *solverProblem, int port);
};

#endif //SEARCHINGALGOSERVER_MyTestClientHandler_H