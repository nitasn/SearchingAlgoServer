//
// Created by hodyah on 19.1.2020.
//

#ifndef SEARCHINGALGOSERVER_MATRIXSEARCHABLE_H
#define SEARCHINGALGOSERVER_MATRIXSEARCHABLE_H


#include <istream>
#include <tuple>
#include "Searchable.h"
#include <vector>

typedef std::pair<int, int> coords;

class matrixSearchable : public Searchable<coords>
{
    std::vector<std::vector<int>> matrix;

    int numRows = 0;
    int numColumns = 0;
    coords start;
    coords goal;
    double minWeight{};

    void createTheMatrix(std::vector<std::string> &stringVector);

    void findValue(std::vector<std::string>::iterator itToStringVector,
                   std::string *stringOfNum, size_t *i);

    void findAllValueInLine(std::vector<std::string>::iterator itToStringVector,
                            std::string *k, std::string *j);

    bool thisIsBlock(int i, int j);

public:
    double getWeight(coords t1, coords t2) override;

    explicit matrixSearchable(std::vector<std::string> &stringVector);

    coords getStart() override;

    coords getGoal() override;

    std::list<coords> getNeighbors(coords object) override;

    double getMinimalWeight() override
    {
        return minWeight;
    }

    double getCellCost(coords &ij)
    {
        return matrix[ij.first][ij.second];
    }
};

#endif //SEARCHINGALGOSERVER_MATRIXSEARCHABLE_H
