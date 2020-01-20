//
// Created by hodyah on 19.1.2020.
//

#include <vector>
#include "matrixSearchable.h"
using namespace std;
const int NUM_OF_END_LINE_TO_REMOVE = 2;

matrixSearchable::matrixSearchable(std::vector<std::string> stringVector) {
    createTheMatrix(stringVector);
}

void matrixSearchable::createTheMatrix(std::vector<std::string> stringVector) {
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
            rowVector.push_back(stoi(stringOfNum));
            stringOfNum.clear();
        }
            if (stringOfNum.length() != 0) {
                rowVector.push_back(stoi(stringOfNum));
                stringOfNum.clear();
                if (thisFirstName) { this->numRows++; }
            }
        }
    matrix.push_back(rowVector);
    rowVector.clear();
    thisFirstName = false;
    this->numColumns += 1;
    string k = 0, j = 0;
    findAllValueInLine(itToStringVector, &k, &j);
    this->first = {stoi(j), stoi(k)};
    k.clear();
    j.clear();
    findAllValueInLine(++itToStringVector, &k, &j);
    this->goal = {stoi(j),stoi(k)};
}

void  matrixSearchable::findValue(vector<string>::iterator itToStringVector, string* stringOfNum, int *i){
        while ((*itToStringVector)[*i] != ',' && *i < itToStringVector->length()) {
            if ((*itToStringVector)[*i] != ' ') {
                *stringOfNum += itToStringVector[*i];
            }
            (*i)++;
        }
}

void  matrixSearchable::findAllValueInLine(vector<string>::iterator itToStringVector,
        string *k, string *j){
    for (int i = 0; i < itToStringVector->length(); i++) {
        findValue(itToStringVector, j, &i);
        findValue(itToStringVector, k, &i);
    }
}

coords matrixSearchable::getStart(){
    return this->first;
}
coords matrixSearchable::getGoal(){
    return this->goal;
}
std::list<coords> matrixSearchable::getNeighbors(coords ij){
    
}