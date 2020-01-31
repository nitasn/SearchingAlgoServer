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
    std::multimap<double, State> mapOfCost;
    std::map<State, State> mapFather;

public:
    /**
     * findTheAnswer find the best way with smallest cost for this way.
     * the way finding with Best fs algoritam.
     * @return pointer to state list with the state in best way, start from goal.
     */
    std::list<State> *findPath(Searchable<State> *_graph) override
    {
        mapOfCost.clear();
        mapFather.clear();
        this->graph = _graph;

        mapOfCost.insert(std::pair<double, State>(0, graph->getStart()));
        mapFather[graph->getStart()] = graph->getStart();
        while(!mapOfCost.empty()){
            State state = mapOfCost.begin()->second;
            double costCurrentWay = mapOfCost.begin()->first;
            mapOfCost.erase(mapOfCost.begin());
            if (state == graph->getGoal())
            {
                return updateTheWay();
            }
            for (auto neighbors :graph->getNeighbors(state)){
                if(mapFather.count(neighbors) == 0){
                    mapFather[neighbors] = state;
                    mapOfCost.insert(std::pair<double, State>(costCurrentWay +
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
    std::list<State> *updateTheWay()
    {
        auto *listState = new std::list<State>;

        State father = mapFather[graph->getGoal()];
        listState->push_front(graph->getGoal());
        while(father != this->graph->getStart()){
            listState->push_front(father);
            father = mapFather[father];
        }

        if (graph->getStart() != graph->getGoal()) // magnificent plaster
            listState->push_front(this->graph->getStart());

        std::cout << "best_fs touched " << mapFather.size() << " states" << std::endl; // todo delete this line
        return listState;
    }
};

#endif //SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H