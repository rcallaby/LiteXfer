#include "request_handler.h"
#include <iostream>
#include <unistd.h>
#include <cstring>

RequestHandler::RequestHandler(int client_sock) : client_socket(client_sock) {}

RequestHandler::~RequestHandler() {
    if (client_socket > 0) {
        close(client_socket);
    }
}

void RequestHandler::handleRequest() {
    handleGetRequest(); // Currently handles only GET requests
}

void RequestHandler::handleGetRequest() {
    sendResponse("Default GET Response");
}

void RequestHandler::sendResponse(const std::string &response) {
    const std::string http_response = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Length: " + std::to_string(response.size()) + "\r\n"
        "Content-Type: text/plain\r\n\r\n" + 
        response;
    send(client_socket, http_response.c_str(), http_response.size(), 0);
}
