//
// Created by danial on 10/28/22.
//

#ifndef SIMPLE_HTTP_SERVER_HTTPREQUEST_H
#define SIMPLE_HTTP_SERVER_HTTPREQUEST_H

#include "string"

using namespace std;

class HttpRequest {
    string url;

public:
    HttpRequest(const string &body);

    //    string getMethod();

    string getUrl();

//    string getHttpVersion();
};


#endif //SIMPLE_HTTP_SERVER_HTTPREQUEST_H
