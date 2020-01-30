//
// Created by Nitsan BenHanoch on 23/01/2020.
//

#ifndef SEARCHINGALGOSERVER_OA_H
#define SEARCHINGALGOSERVER_OA_H

#include "Solver.h"
#include "Searcher.h"
#include "matrixSearchable.h"

//                                    problem      solution
class OA : public server_side::Solver<std::string, std::string>
{
    Searcher<coords> *searcher;

public:

    explicit OA(Searcher<coords> *searcher) : searcher(searcher) {}

    std::string getSolution(std::string &problem) override;
};

#endif //SEARCHINGALGOSERVER_OA_H
