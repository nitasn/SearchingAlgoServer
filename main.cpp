#include "matrixSearchable.h"
#include "Searchable.h"
#include <iostream>
#include "algorithmDFS.h"
#include "algorithmBFS.h"
#include "algorithmA_star.h"
#include "FileCacheManager.h"
#include "algorithmBestFirstSearch.h"
#include "SerialServer.h"
#include "OA.h"
#include "ParallelServer.h"
#include "log_info.h"

using namespace std;

void sleep_forever()
{
    auto forever = chrono::system_clock::now() + chrono::hours(numeric_limits<int>::max());
    this_thread::sleep_until(forever);
}

int main()
{
    algorithmA_star<coords> algo;

    auto *searcher = dynamic_cast<Searcher<coords> *>(&algo); // down casting

    OA oa(searcher);

    auto *solver = dynamic_cast<server_side::Solver<string, string> *>(&oa); // down casting again


    server_side::ClientHandler clientHandler(solver);

    server_side::ParallelServer server(5600, &clientHandler);

    sleep_forever();
}