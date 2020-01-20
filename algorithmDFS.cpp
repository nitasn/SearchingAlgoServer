//
// Created by Nitsan BenHanoch on 20/01/2020.
//

#include "algorithmDFS.h"

using namespace std;

template<typename State> std::list<State> *algorithmDFS<State>::recursivePathFinder(State state)
{
    if (visited.find(state) == visited.end()) // אם עוד לא ביקרנו בקודקוד הזה
    {
        visited.add(state);

        auto graph = Searcher<Searchable<State>, std::list<State>>::problem; // פשוט שם מקוצר

        if (graph->getGoal() == state)
        {
            auto *lst = new list<State>;
            lst->push_back(state);
            return lst;
        }

        for (State neighbor : graph->getNeighbors(state))
        {
            auto way = recursivePathFinder(neighbor);

            if (way != nullptr)
            {
                way->push_back(state);
                return way;
            }
        }
    }
    return nullptr;
}

template<typename State> list<State> *algorithmDFS<State>::findTheAnswer()
{
    auto graph = Searcher<Searchable<State>, std::list<State>>::problem; // פשוט שם מקוצר

    return recursivePathFinder(graph->getStart());
}
