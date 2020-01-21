//
// Created by Nitsan BenHanoch on 20/01/2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMDFS_H
#define SEARCHINGALGOSERVER_ALGORITHMDFS_H

#include "Searcher.h"
#include "SearcherAbstarct.h"
#include <set>
#include <list>

template<typename State> class algorithmDFS : public Searcher<Searchable<State>, std::list<State> *>
{
    std::set<State> visited;
    std::list<State> *recursivePathFinder(State state);
public:
    std::list<State> *findTheAnswer() override;
};

#endif //SEARCHINGALGOSERVER_ALGORITHMDFS_H
