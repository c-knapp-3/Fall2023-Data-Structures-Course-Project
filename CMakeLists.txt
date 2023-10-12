cmake_minimum_required(VERSION 3.26)
project(Git_Group_Project)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "SpellChecker/*.cpp")
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "SpellChecker/*.h")

add_executable(Git_Group_Project
        ${SOURCES}
        ${HEADERS}
        Data/words_alpha.txt
        SpellChecker/SpellChecker/Utils.cpp
        SpellChecker/SpellChecker/Utils.h
        SpellChecker/SpellChecker/MagicDict.cpp
        SpellChecker/SpellChecker/MagicDict.h
        SpellChecker/SpellChecker/MagicDict.h)
