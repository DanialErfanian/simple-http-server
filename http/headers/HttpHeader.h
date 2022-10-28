//
// Created by danial on 10/28/22.
//

#ifndef SIMPLE_HTTP_SERVER_HTTPHEADER_H
#define SIMPLE_HTTP_SERVER_HTTPHEADER_H

#include "string"

using namespace std;

class HttpHeader {
    string key;
    string value;

public:
    HttpHeader(const string &key, const string &value) {
        this->key = key;
        this->value = value;
    }

public:
    string getKey();

    string getValue();
};


#endif //SIMPLE_HTTP_SERVER_HTTPHEADER_H
