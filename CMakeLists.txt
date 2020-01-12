cmake_minimum_required(VERSION 3.15)
project(SearchingAlgoServer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(
        SearchingAlgoServer
        main.cpp
        server_side.h
        CacheManager.h
        MySerialServer.h
        MySerialServer.cpp
        Solver.h
        StringReverser.cpp
        StringReverser.h
        FileCacheManager.cpp
        FileCacheManager.h
)
