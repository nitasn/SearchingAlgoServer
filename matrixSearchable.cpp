//
// Created by hodyah on 19.1.2020.
//

#include <vector>
#include <queue>
#include "matrixSearchable.h"
#include <cmath>

using namespace std;
const int NUM_OF_END_LINE_TO_REMOVE = 2;
const int WALL = -1;



matrixSearchable::matrixSearchable(std::vector<std::string> &stringVector) {
    createTheMatrix(stringVector);
}

void matrixSearchable::createTheMatrix(std::vector<std::string> &stringVector) {
    int minW = INFINITY;
    std::vector<int> rowVector;
    bool thisFirstName = true;
    std::string stringOfNum;
    auto itToEndMatrix = (stringVector.end() - 2);
    auto itToStringVector = stringVector.begin();
    for (; itToStringVector != itToEndMatrix; itToStringVector++) {
        *itToStringVector = itToStringVector->substr(0, itToStringVector->length() - NUM_OF_END_LINE_TO_REMOVE);
        for (size_t i = 0; i < itToStringVector->length(); i++) {
            findValue(itToStringVector, &stringOfNum, &i);
            if (stringOfNum.length() != 0) {
                int value = stoi(stringOfNum);
                rowVector.push_back(value);
                if (value != WALL && value < minW)
                    minW = value;
                stringOfNum.clear();
                if (thisFirstName) { this->numColumns++; }
            }else{
                ++i;
            }
        }
        matrix.push_back(rowVector);
        rowVector.clear();
        thisFirstName = false;
        this->numRows += 1;
    }
    string k, j;
    findAllValueInLine(itToStringVector, &k, &j);
    this->start = {stoi(j), stoi(k)};
    k.clear();
    j.clear();
    findAllValueInLine(++itToStringVector, &k, &j);
    this->goal = {stoi(j),stoi(k)};
    this->minWeight = minW;
}

void  matrixSearchable::findValue(vector<string>::iterator itToStringVector, string* stringOfNum, size_t *i){
        while ((*itToStringVector)[*i] != ',' && *i < itToStringVector->length()) {
            if ((*itToStringVector)[*i] != ' ') {
                *stringOfNum += (*itToStringVector)[*i];
            }
            (*i)++;
        }
        (*i)++;
}

void  matrixSearchable::findAllValueInLine(vector<string>::iterator itToStringVector,
        string *k, string *j){
    for (size_t i = 0; i < itToStringVector->length(); i++) {
        findValue(itToStringVector, j, &i);
        findValue(itToStringVector, k, &i);
    }
}

coords matrixSearchable::getStart(){
    return this->start;
}
coords matrixSearchable::getGoal(){
    return this->goal;
}
std::list<coords> matrixSearchable::getNeighbors(coords ij){
    std::list<coords> listNeighbors;

    if ((ij.first != 0) && !thisIsBlock(ij.first - 1, ij.second)){
        coords up = {(ij.first - 1), (ij.second)};
        listNeighbors.push_back(up);
    }
    if ((ij.first != (this->numRows -1)) && !thisIsBlock(ij.first + 1, ij.second)){
        coords down = {(ij.first + 1), (ij.second)};
        listNeighbors.push_back(down);
    }
    if ((ij.second != 0) && !thisIsBlock(ij.first, ij.second - 1)){
        coords left = {(ij.first), (ij.second - 1)};
        listNeighbors.push_back(left);
    }
    if ((ij.second != (this->numColumns -1)) && !thisIsBlock(ij.first, ij.second + 1)){
        coords right = {(ij.first), (ij.second + 1)};
        listNeighbors.push_back(right);
    }
    return listNeighbors;
}

bool matrixSearchable::thisIsBlock(int i, int j){
    auto itToVector = this->matrix.begin();
    itToVector += i;
    auto itToNum = itToVector->begin();
    itToNum += j;
    return *itToNum == WALL;
}

double matrixSearchable::getWeight(coords t1, coords t2) {

    auto itToVector = this->matrix.begin();
    itToVector += t2.first;
    auto itToNum = itToVector->begin();
    itToNum += t2.second;
    return *itToNum;

//   todo todo why not just
//   return this->matrix[t2.first][t2.second];
}
