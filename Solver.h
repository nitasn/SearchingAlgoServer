//
// Created by hodyah on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_SOLVER_H
#define SEARCHINGALGOSERVER_SOLVER_H


template<typename Problem, typename Solution> struct Solver {
//    virtual Solution *solve(Problem *) = 0;
    //todo solver - check if semothing in chcah, or solve him
    virtual std::vector<Solution>* solve(std::vector<Problem> stringVector) = 0;
};


#endif //SEARCHINGALGOSERVER_SOLVER_H
