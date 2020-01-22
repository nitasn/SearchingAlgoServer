//
// Created by hodyah on 19.1.2020.
//

#ifndef SEARCHINGALGOSERVER_MATRIXSEARCHABLE_H
#define SEARCHINGALGOSERVER_MATRIXSEARCHABLE_H

//struct coords
//{
//    int I, J;
//};
#include <istream>
#include <tuple>
#include "Searchable.h"
enum {I, J, VALUE, SUM_OF_WAY};
typedef std::tuple<int, int, int, int> coords;
//typedef std::pair<int, int> coords;
struct CompareWayState{
    //todo this is not good! < not for State!
    bool operator()(coords s1,coords s2){
        return get<SUM_OF_WAY>(s1) > get<SUM_OF_WAY>(s2);
    }
};
class matrixSearchable: public Searchable<coords> {
    int numRows = 0;
    int numColumns = 0;
    coords start;
    coords goal;
    void createTheMatrix(std::vector<std::string> &stringVector);
    void findValue(std::vector<std::string>::iterator itToStringVector,
            std::string* stringOfNum, int *i);
    void findAllValueInLine(std::vector<std::string>::iterator itToStringVector,
            std::string *k, std::string *j);
    bool thisIsBlock(int i, int j);
public:
    int returnValueThe(int i, int j);
    std::vector<std::vector<int>> matrix; // TODO MAKE PRIVATE
    explicit matrixSearchable(std::vector<std::string> &stringVector);
    coords getStart() override;
    coords getGoal() override;
    std::list<coords> getNeighbors(coords object) override;
    int getWayNum(coords coordsObj) override ;
    void addToWayNum(coords coordsObj, int num) override;
    int getValueOfState(coords coordsObj) override;
};

#endif //SEARCHINGALGOSERVER_MATRIXSEARCHABLE_H
