//
// Created by hodyah on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_SOLVER_H
#define SEARCHINGALGOSERVER_SOLVER_H

namespace server_side
{
    template<typename Problem, typename Solution>
    struct Solver
    {
        virtual Solution getSolution(Problem &problem) = 0;
    };
}

#endif //SEARCHINGALGOSERVER_SOLVER_H
