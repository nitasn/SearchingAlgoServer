//
// Created by hodyah on 12/01/2020.
//

#include <string>
#include <sstream>
#include "Solver.h"
#include "string.h"
#include "algorithm"

//class StringReverser: public Solver<std::string, std::string>{
class StringReverser: public Solver{
public:
    std::string* solve(std::string* inputStream)
    {
        std::stringstream stringOfStream;
        reverse(inputStream->begin(),inputStream->end());
        return inputStream;
    }

};