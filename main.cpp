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

using namespace std;

void sleep_forever()
{
    auto forever = chrono::system_clock::now() + chrono::hours(numeric_limits<int>::max());
    this_thread::sleep_until(forever);
}

int main()
{
    Searcher<coords> *searcher = new algorithmBestFirstSearch<coords>;

    server_side::Solver<string, string> *solver = new OA(searcher);

    server_side::ClientHandler clientHandler(solver);

    server_side::ParallelServer server(5400, &clientHandler);

    sleep_forever();
}