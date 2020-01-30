cmake_minimum_required(VERSION 3.15)
project(SearchingAlgoServer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(
        SearchingAlgoServer
        BaseServer.cpp
        BaseServer.h
        CacheManager.h
        ClientHandler.h
        FileCacheManager.cpp
        FileCacheManager.h
        OA.cpp
        OA.h
        ParallelServer.cpp
        ParallelServer.h
        Searchable.h
        Searcher.h
        SerialServer.cpp
        SerialServer.h
        Solver.h
        algorithmA_star.h
        algorithmBFS.h
        algorithmBestFirstSearch.h
        algorithmDFS.h
        log_info.cpp
        log_info.h
        main.cpp
        matrixSearchable.cpp
        matrixSearchable.h
)
