//
// Created by hodyah on 19.1.2020.
//

#include <vector>
#include "matrixSearchable.h"

const int NUM_OF_END_LINE_TO_REMOVE = 2;

matrixSearchable::matrixSearchable(std::vector<std::string> stringVector) {
    createTheMatrix(stringVector);
}

void matrixSearchable::createTheMatrix(std::vector<std::string> stringVector){
    std::vector<int> rowVector;
    bool thisFirstName = true;
    std::string stringOfNum;
    //todo
    auto itToEndMatrix = (stringVector.end()-2);
    for(std::vector<std::string>::iterator itToStringVector = stringVector.begin(); itToStringVector !=itToEndMatrix; itToStringVector++) {
        *itToStringVector = itToStringVector->substr(0,itToStringVector->length()- NUM_OF_END_LINE_TO_REMOVE);
        for (int i = 0; i < itToStringVector->length(); i++){
            while ((*itToStringVector)[i] != ',' && i < itToStringVector->length()){
                if ((*itToStringVector)[i] != ' '){
                    stringOfNum += itToStringVector[i];
                }
                i++;
            }
            if (stringOfNum.length() != 0){
                rowVector.push_back(stoi(stringOfNum));
                stringOfNum.clear();
                if(thisFirstName){this->numRows++;}
            }
        }
        matrix.push_back(rowVector);
        rowVector.clear();
        thisFirstName = false;
        this->numColumns += 1;
    }
    for (it)
}

std::vector<coords> matrixSearchable::getTheProblem(){

}