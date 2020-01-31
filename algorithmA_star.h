//
// Created by Nitsan BenHanoch on 22/01/2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMA_STAR_H
#define SEARCHINGALGOSERVER_ALGORITHMA_STAR_H


#include <queue>

#include "Searcher.h"
#include <set>
#include <list>
#include <map>
#include <cmath>

template <typename State>
class algorithmA_star : public Searcher<State>
{
    class PopFromEmptyHeap : std::exception {};

    std::map<State, double> cost_until_here; // כמה עלה להגיע מקודקוד ההתחלה עד כאן

    std::multimap<double, State> _costs2states; // states that cost that much (sorted from min cost) used as heap
    std::map<State, typename std::multimap<double, State>::iterator> _heap_iters; // for fast deletion

    std::set<State> CLOSED; // states we're done exploring
    std::map<State, State> fathers;

    Searchable<State> *graph;

    double heuristic_cost_to_goal(State &s)
    {
        const State &t = graph->getGoal();
        int diff = abs(t.first - s.first) + abs(t.second - s.second);
        return diff * graph->getMinimalWeight();
    }

    State pop_min()
    {
        if (_costs2states.empty()) throw PopFromEmptyHeap();

        double min_cost = _costs2states.begin()->first;

        auto best_states_range = _costs2states.equal_range(min_cost);

        auto _begin = best_states_range.first;
        auto _end = best_states_range.second;

        // looping over states scoring min cost, to find the one with min heuristic dist from goal

        double min_h = INFINITY;
        typename std::multimap<double, State>::iterator result_iter;

        for (auto cost_n_state = _begin; cost_n_state != _end; cost_n_state++)
        {
            double h = heuristic_cost_to_goal(cost_n_state->second);

            if (h < min_h)
            {
                min_h = h;
                result_iter = cost_n_state;
            }
        }

        State result = result_iter->second;

        _costs2states.erase(result_iter);
        _heap_iters.erase(result);

        return result;
    }

    void insert_or_update(State &s, double cost)
    {
        if (_heap_iters.find(s) != _heap_iters.end()) {
            auto iter = _heap_iters[s];
            _costs2states.erase(iter);
        }
        auto iter = _costs2states.emplace(cost, s);
        _heap_iters[s] = iter;
    }

public:

    // todo this one is effectively constructor... we should change the api so that oa gets searcher by template and not by pointer to interface
    std::list<State> *findPath(Searchable<State> *_graph) override
    {
        cost_until_here.clear();
        _costs2states.clear();
        _heap_iters.clear();
        CLOSED.clear();
        fathers.clear();

        this->graph = _graph;

        State first = graph->getStart();
        cost_until_here[first] = 0;
        insert_or_update(first, heuristic_cost_to_goal(first));

        while (true)
        {
            if (_heap_iters.empty()) return nullptr;

            State current = pop_min();

            CLOSED.insert(current);

            if (graph->getGoal() == current)
                break;

            for (State &neighbor : graph->getNeighbors(current)) if (CLOSED.find(neighbor) == CLOSED.end())
                {
                    bool in_heap = _heap_iters.find(neighbor) != _heap_iters.end();

                    bool found_shorter_way = in_heap && // ladies and gents, the triangle inequality:
                                             cost_until_here[current] + graph->getWeight(current, neighbor)
                                             < cost_until_here[neighbor];

                    if (!in_heap || found_shorter_way)
                    {
                        cost_until_here[neighbor] = cost_until_here[current] + graph->getWeight(current, neighbor);
                        double heuristic_f = cost_until_here[neighbor] + heuristic_cost_to_goal(neighbor);
                        fathers[neighbor] = current;
                        insert_or_update(neighbor, heuristic_f);
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


#endif //SEARCHINGALGOSERVER_ALGORITHMA_STAR_H
