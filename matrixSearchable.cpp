//
// Created by hodyah on 19.1.2020.
//

#include <vector>
#include <queue>
#include "matrixSearchable.h"
using namespace std;
const int NUM_OF_END_LINE_TO_REMOVE = 2;
const int INFINITE = -1;

matrixSearchable::matrixSearchable(std::vector<std::string> &stringVector) {
    createTheMatrix(stringVector);
}

void matrixSearchable::createTheMatrix(std::vector<std::string> &stringVector) {
    std::vector<int> rowVector;
    bool thisFirstName = true;
    std::string stringOfNum;
    //todo
    auto itToEndMatrix = (stringVector.end() - 2);
    std::vector<std::string>::iterator itToStringVector = stringVector.begin();
    for (; itToStringVector != itToEndMatrix; itToStringVector++) {
        *itToStringVector = itToStringVector->substr(0, itToStringVector->length() - NUM_OF_END_LINE_TO_REMOVE);
        for (int i = 0; i < itToStringVector->length(); i++) {
            findValue(itToStringVector, &stringOfNum, &i);
            if (stringOfNum.length() != 0) {
                rowVector.push_back(stoi(stringOfNum));
                stringOfNum.clear();
                if (thisFirstName) { this->numRows++; }
            }
            ++i;
        }
        matrix.push_back(rowVector);
        rowVector.clear();
        thisFirstName = false;
        this->numColumns += 1;
    }
    string k, j;
    findAllValueInLine(itToStringVector, &k, &j);
    this->start = {stoi(j), stoi(k)};
    k.clear();
    j.clear();
    findAllValueInLine(++itToStringVector, &k, &j);
    this->goal = {stoi(j),stoi(k)};
}

void  matrixSearchable::findValue(vector<string>::iterator itToStringVector, string* stringOfNum, int *i){
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
    for (int i = 0; i < itToStringVector->length(); i++) {
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
    if ((ij.first != (this->numColumns -1)) && !thisIsBlock(ij.first + 1, ij.second)){
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
    std::vector<std::vector<int>>::iterator itToVector = this->matrix.begin();
    itToVector += i;
    std::vector<int>::iterator itToNum = itToVector->begin();
    itToNum += j;
    return *itToNum == INFINITE;
}