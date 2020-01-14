//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "FileCacheManager.h"

using namespace std;
namespace cache_manager
{
    template<typename Problem, typename Solution>
    void store(Problem &problem, Solution &solution)
    {
        throw "not implemented";
    }

    template<typename Problem, typename Solution>
    Solution FileCacheManage::retrieve(string &problem)
    {
        vector<string> optionalFilesOfHaseProblem = ls::get_filenames(getTyped(problem) + "#" + getHase(problem) + "#*", "*.cpp");
        vector<string>::iterator it = optionalFilesOfHaseProblem.begin();
        for(it; it != optionalFilesOfHaseProblem.end(); it++){
//            ofstream file;
//            file.open(cacheFileName(problem), ios::binary);
//            if (!file) { throw CouldNotWriteFile(); }
//
//            size_t problem_length = sizeof(*problem);
//            file.write((char *) problem_length, sizeof(problem_length));
//
//            file.write((char *) problem, sizeof(*problem));
//
//            file.write((char *) solution, sizeof(*solution)); // overrides if exists
//            file.close();
            fstream fileOfProblem;
            fileOfProblem.open(*it, ios::binary);
            if (!fileOfProblem){throw notSeeccsedOpenTheFile();}
            char *bufferSize = nullptr,  *bufferProblem = nullptr;
            string ()
            while (problem)
            fileOfProblem.read(bufferSize, 8);
            fileOfProblem.read(bufferProblem, atoi(bufferSize));
            string bufferString(bufferProblem);

        }
    }

    template<typename Problem, typename Solution>
    bool FileCacheManager<Problem, Solution>::is_cached(Problem *problem)
    {
        throw "not implemented";
    }

}
