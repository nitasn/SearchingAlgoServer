//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#include "FileCacheManager.h"

namespace cache_manager
{
    template<typename Problem, typename Solution>
    void FileCacheManager<Problem, Solution>::store(Problem *problem, Solution *solution)
    {
        throw "not implemented";
    }

    template<typename Problem, typename Solution>
    Solution *FileCacheManager<Problem, Solution>::retrieve(Problem *problem)
    {
        throw "not implemented";
    }

    template<typename Problem, typename Solution>
    bool FileCacheManager<Problem, Solution>::is_cached(Problem *problem)
    {
        throw "not implemented";
    }
}
