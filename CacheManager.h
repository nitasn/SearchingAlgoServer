//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_CACHEMANAGER_H
#define SEARCHINGALGOSERVER_CACHEMANAGER_H

namespace cache_manager
{
    template<typename Problem, typename Solution>
    struct CacheManager
    {
        virtual void store(Problem *problem, Solution *solution) = 0; // לאחסן פיתרון

        virtual Solution *retrieve(Problem *problem) = 0; // למצוא במחסן את הפתרון

        virtual bool is_cached(Problem *problem) = 0; // האם יש פתרון במחסן
    };
}
#endif //SEARCHINGALGOSERVER_CACHEMANAGER_H
