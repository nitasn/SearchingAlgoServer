//
// Created by Nitsan BenHanoch on 20/01/2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMDFS_H
#define SEARCHINGALGOSERVER_ALGORITHMDFS_H

#include "Searcher.h"
#include <set>
#include <list>

template<typename State> class algorithmDFS : public Searcher<State>
{
    std::set<State> visited;

    // מאיזושהי סיבה (בגלל שזה טמפלייט?) אין גישה אליו דרך פשוט ״graph״, למרות שהיינו אמורים לרשת אותו, אז הנה קיצור אליו
    Searchable<State> *graph = Searcher<State>::graph;

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

    explicit algorithmDFS(Searchable<State> *problem) : Searcher<State>(problem) {}

    std::list<State> *findPath() override
    {
        State first = graph->getStart();

        return recursivePathFinder(first);
    }
};

#endif //SEARCHINGALGOSERVER_ALGORITHMDFS_H
