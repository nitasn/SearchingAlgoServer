//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_FILECACHEMANAGER_H
#define SEARCHINGALGOSERVER_FILECACHEMANAGER_H


#include "CacheManager.h"
#include <string>

namespace cache_manager
{
    class FileCacheManager : public CacheManager<std::string, std::string> {

        class notSeeccsedOpenTheFile: public std::exception{};

        void store(std::string &problem, std::string &solution) override;

        std::string retrieve(std::string &problem) override;

        bool is_cached(std::string &problem) override;
    };
}



#endif //SEARCHINGALGOSERVER_FILECACHEMANAGER_H
