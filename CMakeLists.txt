cmake_minimum_required(VERSION 3.19)
project(trigres)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib/cli)
include_directories(lib/util)

add_executable(trigres
        lib/cli/cli.cpp
        lib/cli/cli.hpp
        lib/util/util.cpp
        lib/util/util.hpp
        lib/util/trigo.cpp
        lib/util/trigo.hpp
        src/main.cpp)
