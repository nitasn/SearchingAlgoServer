#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include "FileCacheManager.h"

using namespace std;

std::string filename(string &problem)
{
    size_t h = hash<string>{}(problem);
    return to_string(h);
}

void cache_manager::FileCacheManager::pop_lru_if_at_max_capacity()
{
    if (mru_list.size() >= capacity)
    {
        iters_map.erase(mru_list.back().first); // delete by key of the last element
        mru_list.pop_back();
    }
}

void cache_manager::FileCacheManager::store(string &problem, string &solution)
{
    ofstream file;
    file.open(filename(problem));
    if (!file)
    {
        throw CouldNotOpenFile();
    }
    file.write(solution.c_str(), solution.size());
    file.close();

    if (iters_map.find(problem) == iters_map.end()) // if NOT in lru
    {
        pop_lru_if_at_max_capacity(); // because we are going to insert to lru
    }
    else // if IS in lru
    {
        mru_list.erase(iters_map[problem]); // so it gets to the head of the list
        // no need to erase from map, key's val will just be changed
    }

    mru_list.push_front(pair<string, string>(problem, solution));
    iters_map[problem] = mru_list.begin();
}

std::string cache_manager::FileCacheManager::retrieve(string &problem)
{
    string solution;

    if (iters_map.find(problem) == iters_map.end()) // if NOT in lru, we need to get it from file
    {
        ifstream file;
        file.open(filename(problem));

        if (!file)
        {
            throw UnKnownKey();
        }
        try
        {
            std::stringstream buffer;
            buffer << file.rdbuf();
            solution = buffer.str();
        }
        catch (...)
        {
            file.close();
            throw CouldNotInterpretFile();
        }
        file.close();

        pop_lru_if_at_max_capacity(); // because we are going to add to lru
    }
    else // if IS in lru
    {
        solution = iters_map[problem]->second;
        mru_list.erase(iters_map[problem]); // to get it to the head of the list...
    }

    mru_list.push_front(pair<string, string>(problem, solution));
    iters_map[problem] = mru_list.begin();

    return solution;
}

bool cache_manager::FileCacheManager::is_cached(string &problem)
{
    return static_cast<bool>(ifstream(filename(problem)));
}

