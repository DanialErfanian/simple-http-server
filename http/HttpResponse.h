//
// Created by danial on 10/28/22.
//

#ifndef SIMPLE_HTTP_SERVER_HTTPRESPONSE_H
#define SIMPLE_HTTP_SERVER_HTTPRESPONSE_H

#include "string"
#include "vector"
#include "headers/HttpHeader.h"

using namespace std;

class HttpResponse {
    int status_code;
    vector<HttpHeader> headers;
    string body;

public:
    void addHeader(const HttpHeader &header);

    void setStatusCode(int statusCode);

    void setBody(const string& newBody);

    string getData();

private:
    static string joinLines(const vector<string> &lines);
};


#endif //SIMPLE_HTTP_SERVER_HTTPRESPONSE_H
