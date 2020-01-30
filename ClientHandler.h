#ifndef SERVER_TEST_CLIENTHANDLER_H
#define SERVER_TEST_CLIENTHANDLER_H

#include <iostream>
#include "Solver.h"
#include "FileCacheManager.h"

namespace server_side
{
    class ClientHandler
    {
        Solver<std::string, std::string> *solver;

        cache_manager::FileCacheManager cache;

    public:

        explicit ClientHandler(Solver<std::string, std::string> *solver) : solver(solver) {}

        std::string handle_client(std::string &question)
        {
            if (cache.is_cached(question))
            {
                return cache.retrieve(question);
            }

            std::string answer = solver->getSolution(question);

            cache.store(question, answer);

            return answer;
        }
    };
}

#endif //SERVER_TEST_CLIENTHANDLER_H