cmake_minimum_required(VERSION 3.2)
project(proj2)

set(CMAKE_CXX_STANDARD 17)


include_directories(src)

add_executable(proj2
    src/crow_all.h
    src/customers-100000.csv
    src/hashtable.cpp
    src/hashtable.h
    src/Lab.h
    src/Lab.cpp
    src/main.cpp
    src/n_ary.cpp
    src/n_ary.h
    src/randomGeneratedData.cpp
    src/randomGeneratedData.h)


