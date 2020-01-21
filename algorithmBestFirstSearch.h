//
// Created by hodyah on 21.1.2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H
#define SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H
#include <Searcher.h>
#include "SearcherAbstarct.h"
#include "matrixSearchable.h"
#include <queue>
#include <set>

//using namespace std;
template <typename State>
class algorithmBestFirstSearch: public Searcher<Searchable<State>, std::list<State> *> {
    Searchable<State> *graph = Searcher<Searchable<State>, std::list<State> *>::problem;
    std::priority_queue<State> *queueState = new std::priority_queue<State>();
    std::set<State> visited;
public:
    explicit algorithmBestFirstSearch(Searchable<State> *problem):
        Searcher<Searchable<State>, std::list<State> *>(problem) {}

    std::list<State> *findTheAnswer() override {
        //todo
        queueState->push(graph->getStart());
        while(!queueState->front()){
            State state = queueState->top();
            visited.insert(state);
            if (state == graph->getGoal()){
                //void updateTheWay()
            }
            // inQueueFriend();


        }
    }
};
#endif //SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H
