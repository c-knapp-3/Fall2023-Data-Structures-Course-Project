#ifndef GIT_GROUP_PROJECT_UTILS_H
#define GIT_GROUP_PROJECT_UTILS_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>

using namespace std;

    //std::string readAllText(std::fstream& in);

    //Removes white space from the back of a string
    inline void rtrim(std::string& s);

#include "Utils.cpp"
#endif //GIT_GROUP_PROJECT_UTILS_H
