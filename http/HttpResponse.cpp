//
// Created by danial on 10/28/22.
//

#include "HttpResponse.h"
#include "string"

using namespace std;


string HttpResponse::getData() {
    vector<string> httpLines = {
            "HTTP/1.1 200 OK",
    };
    for (auto &item: this->headers) {
        httpLines.push_back(item.getKey() + ": " + item.getValue());
    }
    httpLines.emplace_back(""); // to separate headers from http body
    httpLines.push_back(this->body);
    return HttpResponse::joinLines(httpLines);
}

void HttpResponse::addHeader(const HttpHeader &header) {
    this->headers.push_back(header);
}

void HttpResponse::setStatusCode(int statusCode) {
    this->status_code = statusCode;
}

string HttpResponse::joinLines(const vector<string> &lines) {
    string delim = "\r\n";
    string ret;
    for (const auto &s: lines) {
        if (!ret.empty())
            ret += delim;
        ret += s;
    }
    return ret;
}

void HttpResponse::setBody(const string &newBody) {
    this->body = newBody;
}
