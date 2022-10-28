//
// Created by danial on 10/28/22.
//

#ifndef SIMPLE_HTTP_SERVER_STATICFILEHANDLER_H
#define SIMPLE_HTTP_SERVER_STATICFILEHANDLER_H


#include "../http/Handler.h"

class StaticFileHandler : public Handler {
    string path;
public:
    explicit StaticFileHandler(const string &file_path);

    HttpResponse handle(const HttpRequest &request) override;
};


#endif //SIMPLE_HTTP_SERVER_STATICFILEHANDLER_H
