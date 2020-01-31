//
// Created by Nitsan BenHanoch on 29/01/2020.
//
#include <iostream>
#include "log_info.h"


using namespace std;

class IgnoreStream : public ostream
{
public:
    IgnoreStream() : ostream(nullptr) {}

    IgnoreStream(const IgnoreStream &) : ostream(nullptr) {}
};

template<class T>
const IgnoreStream &operator<<(IgnoreStream &&os, const T &value)
{
    return os;
}

IgnoreStream nowhere;

// todo make log_info an object that inherit ostream and contains the methods:
//  + output_to_cout
//  + output_to_nowhere


ostream &log_info = nowhere;
//ostream &log_info = cout;