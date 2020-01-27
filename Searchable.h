//
// Created by hodyah on 19.1.2020.
//

#ifndef SEARCHINGALGOSERVER_SEARCHABLE_H
#define SEARCHINGALGOSERVER_SEARCHABLE_H

#include <list>
/**
 * Searchable the interfice for Searchable grape
 * @tparam State in grape
 */
template<typename State>
class Searchable
{
public:
    virtual State getStart() = 0;

    virtual State getGoal() = 0;

    virtual double getWeight(State t1, State t2) = 0;

    virtual double getMinimalWeight() = 0;

    virtual std::list<State> getNeighbors(State object) = 0;
};

#endif //SEARCHINGALGOSERVER_SEARCHABLE_H
