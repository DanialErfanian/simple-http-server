//
// Created by danial on 10/28/22.
//

#include <fstream>
#include "StaticFileHandler.h"


string readFile(const string &path) {
    string result;
    ifstream file(path);
    if (file.fail()) {
        return "Failed to open file";
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            break;
        } else {
            result += line;
        }
    }
    return result;
}


HttpResponse StaticFileHandler::handle(const HttpRequest &request) {
    HttpResponse response;
    response.setStatusCode(200);
    response.addHeader(HttpHeader("Content-Type", "text/html; charset=utf-8"));
    response.setBody(readFile(this->path));

    return response;
}

StaticFileHandler::StaticFileHandler(const string &file_path) {
    this->path = file_path;
}
