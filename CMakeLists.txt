cmake_minimum_required(VERSION 3.26)
project(word_search)

set(CMAKE_CXX_STANDARD 17)

add_executable(word_search main.cpp
        word_search.cpp
        word_search.h
        menu.cpp
        menu.h
        puzzle_generator.cpp
        puzzle_generator.h
        puzzle_opener.cpp
        puzzle_opener.h
        puzzle_solver.cpp
        puzzle_solver.h
)
