#include "file_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>

FileHandler::FileHandler(int client_sock) : RequestHandler(client_sock) {}

void FileHandler::handleGetRequest() {
    std::string file_name = "index.html"; // Default file name
    std::ifstream file(file_name, std::ios::binary);

    if (file) {
        std::ostringstream file_contents;
        file_contents << file.rdbuf();
        std::string file_data = file_contents.str();

        // Sending HTTP headers
        sendResponse("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");

        // Send the file contents
        sendResponse(file_data);
    } else {
        // If file not found, send 404 response
        sendResponse("HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>");
    }
}
