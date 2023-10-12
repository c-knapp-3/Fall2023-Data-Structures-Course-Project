#ifndef GIT_GROUP_PROJECT_UTILS_CPP
#define GIT_GROUP_PROJECT_UTILS_CPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>

#include "Utils.h"

using namespace std;

//std::string Utils::readAllText(std::fstream &in)
//{
//    std::ostringstream sstr;
//    sstr << in.rdbuf();
//    return sstr.str();
//}

inline void rtrim(std::string& s)
{
	int i = s.length();
	int counter = 0;
	while (!isalpha(s[--i]))
		counter++;
	s = s.substr(0, s.length() - counter);
}


#endif //GIT_GROUP_PROJECT_UTILS_CPP
