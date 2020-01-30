//
// Created by hodyah on 21.1.2020.
//


#ifndef SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H
#define SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H
#include "Searcher.h"
#include "matrixSearchable.h"
#include <queue>
#include <set>
#include <map>

template <typename State>
/**
 * algorithmBestFirstSearch Implementing Searcher with State problem and pointer to
 * list state for sholtion.
 * algorithmBestFirstSearch find the best way for start state from goul state
 * with the smallest cost for way.
 * @tparam State in graph that want run on him
 */
class algorithmBestFirstSearch: public Searcher<State> {
    Searchable<State> *graph;
    std::multimap<double, State> mapOfcost;
    std::map<State, State> *mapFather = new std::map<State, State>();;
    std::list<State> listState;

public:
    /**
     * findTheAnswer find the best way with smallest cost for this way.
     * the way finding with Best fs algoritam.
     * @return pointer to state list with the state in best way, start from goal.
     */
    std::list<State> *findPath(Searchable<State> *_graph) override
    {
        this->graph = _graph;

        mapOfcost.insert(std::pair<double, State>(0, graph->getStart()));
        (*mapFather)[graph->getStart()] = graph->getStart();
        while(!mapOfcost.empty()){
            State state = mapOfcost.begin()->second;
            double costCuurentWay = mapOfcost.begin()->first;
            mapOfcost.erase(mapOfcost.begin());
            if (state == graph->getGoal()){
                updateTheWay();
                return &this->listState;
            }
            for (auto neighbors :graph->getNeighbors(state)){
                if(mapFather->count(neighbors) == 0){
                    (*mapFather)[neighbors] = state;
                    mapOfcost.insert(std::pair<double, State>(costCuurentWay +
                                                              graph->getWeight(state, neighbors), neighbors));
                }
            }
        }
        return nullptr;
    }
    /**
     * updateTheWay run on father map from goal until start state,
     * and add the state for list
     */
    void updateTheWay(){
        State father = (*mapFather)[graph->getGoal()];
        listState.push_front(graph->getGoal());
        while(father != this->graph->getStart()){
            listState.push_front(father);
            father = (*mapFather)[father];
        }
        listState.push_front(this->graph->getStart());
    }

    /**
     * delete the algorithm object
     */
    ~algorithmBestFirstSearch(){
        delete this->mapFather;
    }
};

#endif //SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H
