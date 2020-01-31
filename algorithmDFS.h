//
// Created by Nitsan BenHanoch on 20/01/2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMDFS_H
#define SEARCHINGALGOSERVER_ALGORITHMDFS_H

#include "Searcher.h"
#include <set>
#include <list>
#include <map>

/**
 * algorithmDFS implementing sercher with Searchable with state for problem and
 * state list for solution. algorithmDFS find the way for start state from goul state
 * with deap search.
 * @tparam State in graph that want run on him
 */
template<typename State> class algorithmDFS : public Searcher<State>
{

public:
    /**
    * findPath find the way start to goal the way finding with DFS algoritam.
    * @return pointer to state list with the state in way, start to goal.
    */
    std::list<State> *findPath(Searchable<State> *graph) override
    {
        std::set<State> visited;
        std::list<State> stack;
        std::map<State, State> fathers;

        stack.push_back(graph->getStart());
        visited.insert(graph->getStart());

        while (true)
        {
            if (stack.empty())
                return nullptr;

            auto current = stack.back();
            stack.pop_back();

            if (graph->getGoal() == current)
                break;

            for (State &neighbor : graph->getNeighbors(current))
            {
                if (visited.find(neighbor) == visited.end())
                {
                    fathers[neighbor] = current;
                    visited.insert(neighbor);
                    stack.push_back(neighbor);
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

        //                             (visited.size() - 1) to exclude the starting state
        std::cout << "dfs touched " << (visited.size() - 1) << " states" << std::endl; // todo delete this line
        return path;
    }
};

#endif //SEARCHINGALGOSERVER_ALGORITHMDFS_H
