//
// Created by hodyah on 20.1.2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMBFS_H
#define SEARCHINGALGOSERVER_ALGORITHMBFS_H

#include <Searcher.h>
#include <set>
#include <queue>
#include "SearcherAbstarct.h"
#include "matrixSearchable.h"
#include <unordered_map>

//using namespace std;
template <typename State>
class algorithmBFS: public Searcher<Searchable<State>, std::list<State> *> {
    std::set<State> visited;
    std::unordered_map<State, State> mapFather = new std::unordered_map<State, State>();
    std::queue<State> *queueState = new std::queue<State>();
    std::list<State> listState;
    Searchable<State> *graph = Searcher<Searchable<State>, std::list<State> *>::problem;
    void inQueueFriend(State state){
        this->queueState->push(state);
        for (auto frined: graph->getNeighbors(state)) {
            this->queueState->push(frined);
            (mapFather).insert(frined, state);
        }
    }
public:
    explicit algorithmBFS(Searchable<State> *problem):
            Searcher<Searchable<State>, std::list<State> *>(problem) {}



    std::list<State>* findTheAnswer() override {
        //todo when add to list
        mapFather.insert(this->graph->getStart(), nullptr);
        inQueueFriend(this->graph->getStart());
        while (!this->queueState->empty()){
            visited.insert(graph->getStart());
                State state = this->queueState->front();
                if (state == graph->getGoal()) {
                    listState.push_back(state);
                    updateTheWay();
                    return &listState;
                }
                for (auto nighbors : graph->getNeighbors(state)) {
                    if (visited.find(nighbors) == visited.end()) {
                        this->visited.insert(nighbors);
                        inQueueFriend(nighbors);
                    }
                }
                this->queueState->pop();
            }
        return &listState;
    }

    void updateTheWay(){
        State father = mapFather->at(graph->getGoal());
        listState.push_front(graph->getGoal());
        while(father != nullptr){
            listState.push_front(father);
        }
    }


    ~algorithmBFS(){
//        delete this->queueState;
//        delete this->mapFather;
    }
};

#endif //SEARCHINGALGOSERVER_ALGORITHMBFS_H
