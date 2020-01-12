//
// Created by hodyah on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_STRINGREVERSER_H
#define SEARCHINGALGOSERVER_STRINGREVERSER_H

#include <string>
#include "Solver.h"
#include "string.h"


class StringReverser: public  SolverProblem::Solver<std::string, std::string>{
public:
    StringReverser(std::string);
    std::string* solve(std::string*);
};


#endif //SEARCHINGALGOSERVER_STRINGREVERSER_H
