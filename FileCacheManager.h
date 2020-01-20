//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_FILECACHEMANAGER_H
#define SEARCHINGALGOSERVER_FILECACHEMANAGER_H


#include "CacheManager.h"
#include <dirent.h>
#include <cstring>
#include <vector>
#include <string>
#include <fstream>

class ls {
    static bool wild_match(const std::string &str, const std::string &pattern)
    {
        std::string::const_iterator str_it = str.begin();

        for (auto pat_it = pattern.begin(); pat_it != pattern.end(); ++pat_it) {
            switch (*pat_it) {
                case '*': {
                    if (pat_it + 1 == pattern.end()) {
                        return true;
                    }

                    const size_t max = std::strlen(&*str_it);

                    for (size_t i = 0; i < max; ++i) {
                        if (wild_match(&*(pat_it + 1), &*(str_it + i))) {
                            return true;
                        }
                    }

                    return false;
                }
                default:
                    if (*str_it != *pat_it) {
                        return false;
                    }

                    ++str_it;
            }
        }

        return str_it == str.end();
    }

public:
    class CouldNotOpenDirectory : std::exception {};

    /** שמות הקבצים בתיקייה כשלהי שמתאימים לתבנית כלשהי */
    static std::vector<std::string> get_filenames(const char *dir_name, const std::string &pattern)
    {
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir(dir_name)) == NULL) throw CouldNotOpenDirectory();

        std::vector<std::string> results;

        while ((ent = readdir(dir)) != NULL) // iterate over all files in directory
        {
            if (wild_match(ent->d_name, pattern)) {
                results.emplace_back(ent->d_name);
            }
        }
        closedir(dir);

        return results;
    }
};

namespace cache_manager
{
    struct FileCacheManager : public CacheManager<std::string, std::string>
    {
        class notSeeccsedOpenTheFile : public std::exception{};

        void store(std::string &problem, std::string &solution) override{
                throw "not implemented";
        };

        std::string retrieve(std::string &problem) override
        {
//        string fileNameStirng = "string#" + str_hash(problem) + "#*";
            std::string fileNameStirng = "a";
            std::vector<std::string> optionalFilesOfHaseProblem = ls::get_filenames(fileNameStirng.c_str(),"*.cpp");
            std::vector<std::string>::iterator it = optionalFilesOfHaseProblem.begin();
            std::fstream fileOfProblem;
            for(it; it != optionalFilesOfHaseProblem.end(); it++){
                fileOfProblem.open(*it, std::ios::binary);
                if (!fileOfProblem){throw cache_manager::FileCacheManager::notSeeccsedOpenTheFile();}
                //todo check what the size
                char *bufferSize = new char[1];
                fileOfProblem.read(bufferSize, 1);
                char* bufferProblem = new char[atoi(bufferSize)];
                fileOfProblem.read(bufferProblem, atoi(bufferSize));
                if (strcmp(problem.c_str(),bufferProblem) == 0){
                    delete(bufferProblem, bufferSize); break; }
                delete(bufferProblem, bufferSize);
                fileOfProblem.close();
            }
            std::string anser;
            fileOfProblem >> anser;
            return anser;
        }

        bool is_cached(std::string &problem) override{
            throw "not implemented";
        }
    };
}


#endif //SEARCHINGALGOSERVER_FILECACHEMANAGER_H
