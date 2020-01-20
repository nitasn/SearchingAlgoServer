//
// Created by Nitsan BenHanoch on 20/01/2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMDFS_H
#define SEARCHINGALGOSERVER_ALGORITHMDFS_H

#include "Searcher.h"
#include "SearcherAbstarct.h"
#include <set>
#include <list>

template<typename State> class algorithmDFS : public Searcher<Searchable<State>, std::list<State> *>
{
    std::set<State> visited;

    Searchable<State> *graph = Searcher<Searchable<State>, std::list<State> *>::problem; // פשוט שם מקוצר

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

    explicit algorithmDFS(Searchable<State> *problem) :
            Searcher<Searchable<State>, std::list<State> *>(problem) {}

    std::list<State> *findTheAnswer() override
    {
        State first = graph->getStart();

        return recursivePathFinder(first);
    }
};

#endif //SEARCHINGALGOSERVER_ALGORITHMDFS_H
