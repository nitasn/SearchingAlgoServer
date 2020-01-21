//
// Created by hodyah on 20.1.2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMBFS_H
#define SEARCHINGALGOSERVER_ALGORITHMBFS_H

#include <Searcher.h>
#include <set>
#include "SearcherAbstarct.h"
#include "matrixSearchable.h"

using namespace std;
template <typename State>
class algorithmBFS: public SearcherAbstarct<Searchable<State>, State> {
    set<State> visited;
    queue<State> *queueState;
    list<State> listState;
    void inQueueFriend(){
        for (auto frined: graph->getNeighbors(graph->getStart())) {
            this->queueState->push(frined);
        }
    }
public:
    list<State> findTheAnswer() override {
        auto graph = Searcher<Searchable<State>, std::list<State>>::problem;
        visited.add(graph->getStart());
        while (!this->queueState->empty()) {
            State state = this->queueState->front();
            inQueueFriend();
            if (state == graph->getGoal()) {
                return listState.add(state);
            }
            for (auto nighbors : graph->getNeighbors(state)) {
                if (visited.find(nighbors) == visited.end()) {
                    this->visited.add(nighbors);
                    inQueueFriend();
                }
            }
        }
    }
};

#endif //SEARCHINGALGOSERVER_ALGORITHMBFS_H
