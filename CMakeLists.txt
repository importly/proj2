cmake_minimum_required(VERSION 3.2)
project(proj2)

set(CMAKE_CXX_STANDARD 20)

# SFML FETCH SECTION
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
)
FetchContent_MakeAvailable(SFML)

include_directories(${SFML_SOURCE_DIR}/include)
file(GLOB_RECURSE SRC "src/*.cpp" "src/*.hpp" "src/*.h")
file(GLOB BASE "*.cpp" "*.hpp" "*.h")

add_executable(proj2 ${SRC} ${BASE}
        src/display.cpp
        src/display.h
        src/display.cpp)

target_link_libraries(proj2 sfml-system sfml-window sfml-graphics sfml-audio)
