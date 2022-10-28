cmake_minimum_required(VERSION 3.23)
project(simple_http_server)

set(CMAKE_CXX_STANDARD 14)
FILE(COPY ${CMAKE_SOURCE_DIR}/static/ DESTINATION ${CMAKE_BINARY_DIR}/static)

add_executable(simple_http_server main.cpp http/HttpResponse.cpp http/HttpResponse.h http/headers/HttpHeader.cpp http/headers/HttpHeader.h utils/string_utils.cpp utils/string_utils.h)
