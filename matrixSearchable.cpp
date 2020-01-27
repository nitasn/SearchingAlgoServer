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
/**
 * matrixSearchable create matrix from vector of vector of int.
 * @param stringVector with the matrix row in string
 */
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
/**
 * findValue return the current num from string vector in this place
 * @param itToStringVector itertor for the row in vector string
 * @param stringOfNum pointer for the string of current num in string matrix
 * @param i place in string
 */
void  matrixSearchable::findValue(vector<string>::iterator itToStringVector, string* stringOfNum, size_t *i){
        while ((*itToStringVector)[*i] != ',' && *i < itToStringVector->length()) {
            if ((*itToStringVector)[*i] != ' ') {
                *stringOfNum += (*itToStringVector)[*i];
            }
            (*i)++;
        }
}
/**
 * findAllValueInLine return place index form string vector
 * @param itToStringVector it to current string
 * @param k string for i
 * @param j string for j
 */
void  matrixSearchable::findAllValueInLine(vector<string>::iterator itToStringVector,
        string *k, string *j){
    for (size_t i = 0; i < itToStringVector->length(); i++) {
        findValue(itToStringVector, j, &i);
        (i)++;
        findValue(itToStringVector, k, &i);
    }
}
/**
 * @return get the start coords
 */
coords matrixSearchable::getStart(){
    return this->start;
}
/**
 * @return get the goal coords
 */
coords matrixSearchable::getGoal(){
    return this->goal;
}
/**
 * getNeighbors
 * @param ij coords for current place
 * @return the neighbors in matrix for ij
 */
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
/**
 * return if this value in place in INFINITE
 * @param i row place
 * @param j columns place
 * @return true if it INFINITE, false else
 */
bool matrixSearchable::thisIsBlock(int i, int j){
    auto itToVector = this->matrix.begin();
    itToVector += i;
    auto itToNum = itToVector->begin();
    itToNum += j;
    return *itToNum == WALL;
}
/**
 * @param t1 start coords
 * @param t2 goal coords
 * @return the value of t2 in matrix
 */
double matrixSearchable::getWeight(coords t1, coords t2) {

    auto itToVector = this->matrix.begin();
    itToVector += t2.first;
    auto itToNum = itToVector->begin();
    itToNum += t2.second;
    return *itToNum;

//   todo why not just
//   return this->matrix[t2.first][t2.second];
}
