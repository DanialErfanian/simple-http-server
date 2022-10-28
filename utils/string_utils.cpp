//
// Created by danial on 10/28/22.
//
#include <iostream>
#include <vector>

using namespace std;

vector<string> split(const string &s, const string &delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

string joinStrings(const vector<string>& lines, const string& delim) {
    string ret;
    for (const auto &s: lines) {
        if (!ret.empty())
            ret += delim;
        ret += s;
    }
    return ret;
}