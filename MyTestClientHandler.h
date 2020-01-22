//
// Created by hodyah on 18.1.2020.
//

#ifndef SEARCHINGALGOSERVER_MyTestClientHandler_H
#define SEARCHINGALGOSERVER_MyTestClientHandler_H

#include <server_side.h>
#include <Solver.h>
#include <functional>

class MyTestClientHandler: public server_side::ClientHandler{
//    Solver<Problem, Solution> solverProblem;
    Solver<std::string, std::string> *solverProblem;
    std::vector<std::string>* theProblem{};
    std::vector<std::string>* anser{};
public:
//    void sendAnserToClient() override;
    void handle(std::vector<std::string> vectorString,
            std::function<void(std::string&)> send) override;
    explicit MyTestClientHandler(Solver<std::string, std::string> *solverProblem);
};

#endif //SEARCHINGALGOSERVER_MyTestClientHandler_H