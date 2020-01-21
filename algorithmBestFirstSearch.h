//
// Created by hodyah on 21.1.2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H
#define SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H
#include <Searcher.h>
#include "SearcherAbstarct.h"
#include "matrixSearchable.h"

//using namespace std;
template <typename State>
class algorithmBestFirstSearch: public Searcher<Searchable<State>, std::list<State> *> {
    Searchable<State> *graph = Searcher<Searchable<State>, std::list<State> *>::problem;
    std::queue<State> *queueState = new std::queue<State>();
public:
    explicit algorithmBestFirstSearch(Searchable<State> *problem):
        Searcher<Searchable<State>, std::list<State> *>(problem) {}

    std::list<State> *findTheAnswer() override {
        queueState->push(graph->getStart());
        while(!queueState->front()){

        }
    }
};
#endif //SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H
