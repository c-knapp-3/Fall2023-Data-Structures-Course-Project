cmake_minimum_required(VERSION 3.26)
project(Git_Group_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Git_Group_Project
        SpellChecker/SpellChecker/SpellChecker.cpp
        words_alpha.txt)
