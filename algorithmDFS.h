//
// Created by Nitsan BenHanoch on 20/01/2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMDFS_H
#define SEARCHINGALGOSERVER_ALGORITHMDFS_H

#include "Searcher.h"
#include <set>
#include <list>
/**
 * algorithmDFS implementing sercher with Searchable with state for problem and
 * state list for solution. algorithmDFS find the way for start state from goul state
 * with deap search.
 * @tparam State in graph that want run on him
 */
template<typename State> class algorithmDFS : public Searcher<State>
{
    std::set<State> visited;

    Searchable<State> *graph;
    /**
     * find for state in recursive way the from him nighbord
     * to goal, and add him self to the list.
     * @param state to find way
     * @return list state to goal
     */
    std::list<State> *recursivePathFinder(State state)
    {
        if (visited.find(state) == visited.end()) // אם עוד לא ביקרנו בקודקוד הזה
        {
            visited.insert(state);

            if (graph->getGoal() == state)
            {
                auto *lst = new std::list<State>;
                lst->push_front(state);
                return lst;
            }

            for (State neighbor : graph->getNeighbors(state))
            {
                auto way = recursivePathFinder(neighbor);

                if (way != nullptr)
                {
                    way->push_front(state);
                    return way;
                }
            }
        }
        return nullptr;
    }

public:
    /**
    * findPath find the way start to goal the way finding with DFS algoritam.
    * @return pointer to state list with the state in way, start to goal.
    */
    std::list<State> *findPath(Searchable<State> *_graph) override
    {
        this->graph = _graph;

        State first = graph->getStart();

        return recursivePathFinder(first);
    }
};

#endif //SEARCHINGALGOSERVER_ALGORITHMDFS_H
