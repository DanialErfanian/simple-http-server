//
// Created by danial on 10/28/22.
//

#ifndef SIMPLE_HTTP_SERVER_HANDLER_H
#define SIMPLE_HTTP_SERVER_HANDLER_H


#include "HttpResponse.h"
#include "HttpRequest.h"

class Handler {
public:
    virtual HttpResponse handle(const HttpRequest &request) = 0;
};


#endif //SIMPLE_HTTP_SERVER_HANDLER_H
