//
// Created by hodyah on 20.1.2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMBFS_H
#define SEARCHINGALGOSERVER_ALGORITHMBFS_H

#include <Searcher.h>
#include <set>
#include <queue>
#include "matrixSearchable.h"
#include <map>

template <typename State>
class algorithmBFS: public Searcher<State> {
    std::map<State, State> *mapFather = new std::map<State, State>();
    std::queue<State> *queueState = new std::queue<State>();

    std::list<State> listState;

    Searchable<State> *graph;

    void inQueueFriend(State state){
        for (auto neighbor: graph->getNeighbors(state)) {
            if (mapFather->find(neighbor) == mapFather->end()) {
                this->queueState->push(neighbor);
                (*mapFather)[neighbor] = state;
            }
        }
    }

public:
    std::list<State>* findPath(Searchable<State> *_graph) override {
        this->graph = _graph;
//        (*mapFather)[this->graph->getStart()] = nullptr;
        inQueueFriend(this->graph->getStart());
        while (!this->queueState->empty()){
                State state = this->queueState->front();
                if (state == graph->getGoal()) {
                    listState.push_back(state);
                    updateTheWay();
                    return &listState;
                }
                inQueueFriend(state);
                this->queueState->pop();
            }
        return nullptr;
    }

    void updateTheWay(){
        State father = (*mapFather)[graph->getGoal()];
        while(father != this->graph->getStart()){
            listState.push_front(father);
            father = (*mapFather)[father];
        }
        listState.push_front(this->graph->getStart());
    }


    ~algorithmBFS(){
        delete this->queueState;
        delete this->mapFather;
    }
};

#endif //SEARCHINGALGOSERVER_ALGORITHMBFS_H
