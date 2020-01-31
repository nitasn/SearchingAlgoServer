#ifndef SERVER_TEST_CLIENTHANDLER_H
#define SERVER_TEST_CLIENTHANDLER_H

#include <iostream>
#include "Solver.h"
#include "FileCacheManager.h"
#include "log_info.h"

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
//            if (cache.is_cached(question))
//            {
//                return cache.retrieve(question); todo re-enable cache
//            }

            std::string answer;

            try
            {
                answer = solver->getSolution(question);
            }
            catch (...)
            {
                log_info << "ClientHandler: exception thrown while trying to find an answer to the question";
                return "\r\nan error occurred :( sorry, could not get an answer to your question. \r\n\r\n";
            }


//            cache.store(question, answer);

            return answer;
        }
    };
}

#endif //SERVER_TEST_CLIENTHANDLER_H