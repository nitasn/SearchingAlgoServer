//
// Created by hodyah on 19.1.2020.
//

#ifndef SEARCHINGALGOSERVER_SEARCHER_H
#define SEARCHINGALGOSERVER_SEARCHER_H

#include <Searchable.h>
template <typename Problem, typename Solution>
class Searcher{

protected:
    Problem * problem;

public:
    explicit Searcher(Problem * problem) : problem(problem) {};

    virtual Solution findTheAnswer() = 0;
    virtual int howNumObjectIOpen() = 0;
    virtual void popPriorityQueue() = 0;
    virtual int getPriorityQueueSize() = 0;
};
#endif //SEARCHINGALGOSERVER_SEARCHER_H
