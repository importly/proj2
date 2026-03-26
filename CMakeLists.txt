cmake_minimum_required(VERSION 3.26)
project(proj2)

set(CMAKE_CXX_STANDARD 20)

add_executable(proj2 src/main.cpp
        src/Lab.cpp
        src/Lab.h
        src/n_ary.cpp
        src/n_ary.h
        src/hashtable.cpp
        src/hashtable.h
        src/randomGeneratedData.cpp)
