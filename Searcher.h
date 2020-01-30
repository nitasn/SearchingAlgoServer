//
// Created by hodyah on 19.1.2020.
//

#ifndef SEARCHINGALGOSERVER_SEARCHER_H
#define SEARCHINGALGOSERVER_SEARCHER_H

#include "Searchable.h"
#include "Solver.h"


template<typename State>
class Searcher
{
public:
    virtual std::list<State> *findPath(Searchable<State> *graph) = 0;
};

#endif //SEARCHINGALGOSERVER_SEARCHER_H
