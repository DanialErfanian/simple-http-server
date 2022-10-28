//
// Created by danial on 10/28/22.
//

#include "HttpResponse.h"
#include "string"
#include "../utils/string_utils.h"

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
    return joinStrings(httpLines, "\r\n");
}

void HttpResponse::addHeader(const HttpHeader &header) {
    this->headers.push_back(header);
}

void HttpResponse::setStatusCode(int statusCode) {
    this->status_code = statusCode;
}

void HttpResponse::setBody(const string &newBody) {
    this->body = newBody;
}
