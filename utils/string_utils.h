//
// Created by danial on 10/28/22.
//

#ifndef SIMPLE_HTTP_SERVER_STRING_UTILS_H
#define SIMPLE_HTTP_SERVER_STRING_UTILS_H

#include "string"
#include <vector>

using namespace std;


string joinStrings(const vector<string> &lines, const string &delim);

vector<string> splitString(const string &s, const string &delimiter);

#endif //SIMPLE_HTTP_SERVER_STRING_UTILS_H
