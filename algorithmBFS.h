//
// Created by hodyah on 20.1.2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMBFS_H
#define SEARCHINGALGOSERVER_ALGORITHMBFS_H

#include "Searcher.h"
#include <set>
#include <queue>
#include "matrixSearchable.h"
#include <map>
/**
 * algorithmBFS implementing sercher with Searchable with state for problem and
 * state list for solution. algorithmBFS find the way for start state from goul state
 * with Breadth search.
 * @tparam State in graph that want run on him
 */
template <typename State>
class algorithmBFS: public Searcher<State>
{

public:
    /**
 * findTheAnswer find the way start to goal the way finding with BFS algoritam.
 * @return pointer to state list with the state in way, start to goal.
*/
    std::list<State>* findPath(Searchable<State> *graph) override
    {
        std::set<State> visited;
        std::list<State> queue;
        std::map<State, State> fathers;

        queue.push_back(graph->getStart());
        visited.insert(graph->getStart());

        while (true)
        {
            if (queue.empty())
                return nullptr;

            auto current = queue.front();
            queue.pop_front();

            if (graph->getGoal() == current)
                break;

            for (State &neighbor : graph->getNeighbors(current))
            {
                if (visited.find(neighbor) == visited.end())
                {
                    fathers[neighbor] = current;
                    visited.insert(neighbor);
                    queue.push_back(neighbor);
                }

            }
        }

        auto *path = new std::list<State>;

        State link = graph->getGoal();
        path->push_front(link);

        while (fathers.find(link) != fathers.end())
        {
            link = fathers[link];
            path->push_front(link);
        }

        return path;
    }
};

#endif //SEARCHINGALGOSERVER_ALGORITHMBFS_H
