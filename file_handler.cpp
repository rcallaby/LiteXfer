#include "file_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>

FileHandler::FileHandler(int client_sock) : RequestHandler(client_sock) {}

void FileHandler::handleGetRequest() {
    std::string file_name = "index.html"; // Default file name
    std::ifstream file(file_name, std::ios::binary);

    if (file) {
        // Determine file size
        file.seekg(0, std::ios::end);
        std::size_t file_size = file.tellg();
        file.seekg(0, std::ios::beg);

        // Sending HTTP headers
        std::ostringstream headers;
        headers << "HTTP/1.1 200 OK\r\n"
                << "Content-Type: text/html\r\n"
                << "Content-Length: " << file_size << "\r\n\r\n";
        sendResponse(headers.str());

        // Send the file contents in chunks
        char buffer[4096];
        while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0) {
            sendResponse(std::string(buffer, file.gcount()));
        }
    } else {
        // Log error (optional)
        std::cerr << "Error: File " << file_name << " not found.\n";

        // If file not found, send 404 response
        sendResponse("HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n"
                     "<html><body><h1>404 Not Found</h1></body></html>");
    }
}
