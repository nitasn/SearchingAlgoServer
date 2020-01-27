//
// Created by Nitsan BenHanoch on 23/01/2020.
//

#ifndef SEARCHINGALGOSERVER_OA_H
#define SEARCHINGALGOSERVER_OA_H

#include "Solver.h"
#include "Searcher.h"
#include "Searchable.h"

template <typename State>
//                       problem            solution
class OA : public Solver<Searchable<State>, std::list<State> *>
{
    Searcher<State> *searcher;

public:

    explicit OA(Searcher<State> *searcher) : searcher(searcher) {}

    std::list<State> *getSolution(Searchable<State> problem) override
    {
        return nullptr;
    }
};

#endif //SEARCHINGALGOSERVER_OA_H
