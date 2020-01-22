//
// Created by hodyah on 19.1.2020.
//

#ifndef SEARCHINGALGOSERVER_SEARCHABLE_H
#define SEARCHINGALGOSERVER_SEARCHABLE_H

#include <list>
template<typename State>
class Searchable{
public:
    virtual int getWayNum(State coordsObj) = 0;
    virtual void addToWayNum(State coordsObj, int num) = 0;
    virtual int getValueOfState(State coordsObj) = 0;
    virtual State getStart() = 0;
    virtual State getGoal() = 0;
    virtual std::list<State> getNeighbors(State object) = 0;
};
#endif //SEARCHINGALGOSERVER_SEARCHABLE_H
