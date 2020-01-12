//
// Created by hodyah on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_SOLVER_H
#define SEARCHINGALGOSERVER_SOLVER_H


template<typename Problem, typename Solution> class Solver {
    
public:
    virtual Solution* solve(Problem*) = 0;
};


#endif //SEARCHINGALGOSERVER_SOLVER_H
