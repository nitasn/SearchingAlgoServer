//
// Created by hodyah on 19.1.2020.
//

#ifndef SEARCHINGALGOSERVER_MATRIXSEARCHABLE_H
#define SEARCHINGALGOSERVER_MATRIXSEARCHABLE_H

//struct coords
//{
//    int i, j;
//};
#include <istream>
#include "Searchable.h"
typedef std::pair<int, int> coords;

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
    std::vector<std::vector<int>> matrix; // TODO MAKE PRIVATE
    explicit matrixSearchable(std::vector<std::string> &stringVector);
    coords getStart() override;
    coords getGoal() override;
    std::list<coords> getNeighbors(coords object) override;
};

#endif //SEARCHINGALGOSERVER_MATRIXSEARCHABLE_H
