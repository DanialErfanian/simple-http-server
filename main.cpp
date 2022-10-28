#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <memory>
#include <stdexcept>

#include <sys/socket.h>
#include <unistd.h>
#include <fstream>
#include <algorithm>
#include "http/HttpResponse.h"
#include "http/HttpRequest.h"
#include "urls.h"

#define PORT 8080

using namespace std;

HttpResponse handleRequest(HttpRequest request) {
    string url = request.getUrl();
    auto handlerItem = handlers.find(url);

    Handler *handler;
    if (handlerItem == handlers.end()) {
        handler = handlers.find("/")->second;
    } else {
        handler = handlerItem->second;
    }
    return handler->handle(request);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address{};
    int opt = 1;
    int addrlen = sizeof(address);
    const int bufferSize = 1024;
    char buffer[bufferSize] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *) &address,
             sizeof(address))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while (true) {
        if ((new_socket
                     = accept(server_fd, (struct sockaddr *) &address,
                              (socklen_t *) &addrlen))
            < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        string request;
        ssize_t result;
        do {
            result = read(new_socket, buffer, bufferSize);
            request += string(buffer);
        } while (result == bufferSize);
        HttpRequest httpRequest = HttpRequest(request);
        cout << httpRequest.getUrl() << endl;
        HttpResponse response = handleRequest(httpRequest);
        string responseData = response.getData();
        cout << responseData.length() << endl;
        send(new_socket, responseData.c_str(), responseData.length(), 0);

        // closing the connected socket
        close(new_socket);
    }
}
