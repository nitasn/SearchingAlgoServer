//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#ifndef SEARCHINGALGOSERVER_FILECACHEMANAGER_H
#define SEARCHINGALGOSERVER_FILECACHEMANAGER_H

#include "CacheManager.h"

template <typename Problem, typename Solution> class FileCacheManager : CacheManager<Problem, Solution>
{
    void store(Problem *problem, Solution *solution) override;

    Solution *retrieve(Problem *problem) override;

    bool is_cached(Problem *problem) override;
};


#endif //SEARCHINGALGOSERVER_FILECACHEMANAGER_H
