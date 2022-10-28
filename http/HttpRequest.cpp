//
// Created by danial on 10/28/22.
//

#include "HttpRequest.h"
#include "vector"
#include "../utils/string_utils.h"

string HttpRequest::getUrl() {
    return this->url;
}

HttpRequest::HttpRequest(const string &body) {
    vector<string> httpLines = splitString(body, "\r\n");
    vector<string> firstLine = splitString(httpLines[0], " ");
    string method = firstLine[0];
    this->url = firstLine[1];
    string httpVersion = firstLine[2];
}
