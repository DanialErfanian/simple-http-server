//
// Created by danial on 10/28/22.
//

#ifndef SIMPLE_HTTP_SERVER_URLS_H
#define SIMPLE_HTTP_SERVER_URLS_H

//
// Created by danial on 10/28/22.
//

#include "map"
#include "string"
#include "http/Handler.h"
#include "handlers/StaticFileHandler.h"

using namespace std;

extern const map<string, Handler *> handlers = {
        {"/",         new StaticFileHandler("static/home.html")},
        {"/page2",    new StaticFileHandler("static/page2.html")},
        {"/duck.jpg", new StaticFileHandler("static/duck.jpg")},
};

#endif //SIMPLE_HTTP_SERVER_URLS_H
