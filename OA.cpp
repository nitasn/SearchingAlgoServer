//
// Created by Nitsan BenHanoch on 30/01/2020.
//

#include "OA.h"
#include <vector>
#include <sstream>
#include "log_info.h"

using namespace std;


/**
 * input: one string:
 * 1, 2\r\n3, 4\r\n
 * output: several strings:
 * 1, 2\r\n
 * 3, 4\r\n
 * @param problem
 * @return
 */
vector<string> splitToLines(string &problem)
{
    string ENDING = "\r\n";
    vector<string> results;
    size_t last = 0, next, NOT_FOUND = -1;

    while (last < problem.size())
    {
        next = problem.find(ENDING, last);
        if (next == NOT_FOUND)
            next = problem.size();
        results.push_back(problem.substr(last, next - last) + ENDING);
        last = next + ENDING.size();
    }
    return results;
}

class IllegalEmptyPath : exception {};
class IllegalTurnInPath : exception {};

string direction_name(int di, int dj)
{
    if (di == 1 && dj == 0) return "down";

    if (di == -1 && dj == 0) return "up";

    if (di == 0 && dj == 1) return "right";

    if (di == 0 && dj == -1) return "left";

    log_info << "tried to make a turn of di=" << di << ", dj=" << dj << "; throwing exception" << endl;
    throw IllegalTurnInPath();
}

string path_description(list<coords> *path, matrixSearchable &matrix)
{
    stringstream builder;

    if (path == nullptr)
    {
        builder << "no path found";
    }
    else
    {
        if (path->begin() == path->end())
        {
            throw IllegalEmptyPath(); // path is not null, but it is empty...
        }
        auto iter = path->begin();
        double totalCost = matrix.getCellCost(*iter);

        builder << "(" << totalCost << ") ";

        while (true)
        {
            coords from = *iter++;
            if (iter == path->end())
                break;

            int di = iter->first - from.first;
            int dj = iter->second - from.second;

            builder << direction_name(di, dj) << " ->";

            totalCost += matrix.getCellCost(*iter);
            builder << " (" << totalCost << ") ";
        }

        builder << "at goal";
    }

    builder << "\r\n";

    return builder.str();
}

string OA::getSolution(string &problem)
{
    auto mat_lines = splitToLines(problem); // matrix wants the lines separated, so let's help a bit

    matrixSearchable matrix(mat_lines);

    auto *graph = dynamic_cast<Searchable<coords> *>(&matrix);

    list<coords> *path = searcher->findPath(graph);

//    if (path == nullptr)
//    {
//        cout << "path is null" << endl;
//    }
//    else {
//        for (auto ij : *path) {
//            cout << "(" << ij.first << ", " << ij.second << ") ";
//        }
//        cout << endl;
//    }
//    return "\r\n";

    return path_description(path, matrix);
}
