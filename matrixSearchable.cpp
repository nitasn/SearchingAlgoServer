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
            }else{
                ++i;
            }
        }
        matrix.push_back(rowVector);
        rowVector.clear();
        thisFirstName = false;
        this->numColumns += 1;
    }
    string k, j;
    findAllValueInLine(itToStringVector, &k, &j);
    this->start = {stoi(j), stoi(k), returnValueThe(stoi(j),stoi(k)), 0};
    k.clear();
    j.clear();
    findAllValueInLine(++itToStringVector, &k, &j);
    this->goal = {stoi(j),stoi(k), returnValueThe(stoi(j),stoi(k)), 0};
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

    if ((get<I>(ij) != 0) && !thisIsBlock(get<I>(ij) - 1, get<J>(ij))){
        int iUp = (get<I>(ij) - 1),jUp = (get<J>(ij));
        coords up = { iUp, jUp, returnValueThe(iUp, jUp), 0};
        listNeighbors.push_back(up);
    }
    if ((get<I>(ij) != (this->numColumns - 1)) && !thisIsBlock(get<I>(ij) + 1, get<J>(ij))){
        int iDown = (get<I>(ij) + 1),jDown = (get<J>(ij));
        coords down = { iDown, jDown, returnValueThe(iDown, jDown), 0};
        listNeighbors.push_back(down);
    }
    if ((get<J>(ij) != 0) && !thisIsBlock(get<I>(ij), get<J>(ij) - 1)){
        int iLeft = (get<I>(ij)), jLeft = (get<J>(ij) - 1);
        coords left = {iLeft, jLeft, returnValueThe(iLeft, jLeft), 0};
        listNeighbors.push_back(left);
    }
    if ((get<J>(ij) != (this->numColumns - 1)) && !thisIsBlock(get<I>(ij), get<J>(ij) + 1)){
        int iRight = (get<I>(ij)), jRight = (get<J>(ij) + 1);
        coords right = {iRight, jRight, returnValueThe(iRight, jRight), 0};
        listNeighbors.push_back(right);
    }
    return listNeighbors;
}

bool matrixSearchable::thisIsBlock(int i, int j){
    auto itToVector = this->matrix.begin();
    itToVector += i;
    auto itToNum = itToVector->begin();
    itToNum += j;
    return *itToNum == INFINITE;
}

int matrixSearchable::returnValueThe(int i, int j){
    std::vector<std::vector<int>>::iterator itToVector = this->matrix.begin();
    itToVector += i;
    std::vector<int>::iterator itToNum = itToVector->begin();
    itToNum += j;
    return *itToNum;
}

void matrixSearchable::addToWayNum(coords coordsObj, int num){
    get<SUM_OF_WAY>(coordsObj) += num;
}

int matrixSearchable::getWayNum(coords coordsObj){
    return get<SUM_OF_WAY>(coordsObj);
}

int matrixSearchable::getValueOfState(coords coordsObj){
    return get<VALUE>(coordsObj);
}
