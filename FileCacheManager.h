//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_FILECACHEMANAGER_H
#define SEARCHINGALGOSERVER_FILECACHEMANAGER_H

#include <string>
#include <list>
#include "CacheManager.h"
#include <unordered_map>

namespace cache_manager
{
    class FileCacheManager : public CacheManager<std::string, std::string>
    {
        // key-value pairs, most recent first.
        // mru_list.back()->first is the least recent cached key
        std::list<std::pair<std::string, std::string>> mru_list;

        // key to iter in the lru list
        std::unordered_map<std::string, std::list<std::pair<std::string, std::string>>::iterator> iters_map;

        int capacity;

        void pop_lru_if_at_max_capacity();

    public:
        explicit FileCacheManager(int capacity = 10) : capacity(capacity) {}

        void store(std::string &problem, std::string &solution) override;

        std::string retrieve(std::string &problem) override;

        bool is_cached(std::string &problem) override;


        class CouldNotOpenFile : std::exception{};

        class UnKnownKey : std::exception{};

        class CouldNotInterpretFile : std::exception{};
    };
}


#endif //SEARCHINGALGOSERVER_FILECACHEMANAGER_H
