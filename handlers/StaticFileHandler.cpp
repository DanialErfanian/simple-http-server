//
// Created by danial on 10/28/22.
//

#include <fstream>
#include "StaticFileHandler.h"
#include "../utils/string_utils.h"


string readFile(const string &path) {
    string result;
    ifstream file(path, std::ios::binary);
    if (file.fail()) {
        return "Failed to open file";
    }
    file.seekg(0, std::ios::end);
    result.reserve(file.tellg());
    file.seekg(0, std::ios::beg);

    result.assign((std::istreambuf_iterator<char>(file)),
                  std::istreambuf_iterator<char>());
    return result;
}


HttpResponse StaticFileHandler::handle(const HttpRequest &request) {
    HttpResponse response;
    response.setStatusCode(200);
    if (stringEndsWith(this->path, ".html")) {
        response.addHeader(HttpHeader("Content-Type", "text/html; charset=utf-8"));
    } else {
        response.addHeader(HttpHeader("Content-Type", "image/jpeg"));
    }
    response.setBody(readFile(this->path));

    return response;
}

StaticFileHandler::StaticFileHandler(const string &file_path) {
    this->path = file_path;
}
