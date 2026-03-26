cmake_minimum_required(VERSION 4.1)
project(proj2)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(proj2
        src/crow_all.h
        src/customers-100000.csv
        src/hashtable.cpp
        src/hashtable.h
        src/Lab.cpp
        src/Lab.h
        src/main.cpp
        src/n_ary.cpp
        src/n_ary.h
        src/randomGeneratedData.cpp
        src/randomGeneratedData.h)
