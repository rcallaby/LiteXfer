#include <stdexcept>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unistd.h> 

namespace {
    // Helper function to split a string by a delimiter
    std::vector<std::string> split(const std::string &str, char delimiter) {
        std::vector<std::string> tokens;
        std::istringstream stream(str);
        std::string token;
        while (std::getline(stream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
}

void RequestHandler::handleRequest() {
    try {
        char buffer[4096];
        ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            throw std::runtime_error("Failed to receive data or connection closed");
        }

        buffer[bytes_received] = '\0';
        std::string request(buffer);

        // Parse the request line
        auto lines = split(request, '\n');
        if (lines.empty()) {
            throw std::runtime_error("Malformed HTTP request");
        }

        auto request_line = split(lines[0], ' ');
        if (request_line.size() < 3) {
            throw std::runtime_error("Invalid HTTP request line");
        }

        const std::string &method = request_line[0];
        const std::string &path = request_line[1];
        const std::string &http_version = request_line[2];

        if (method == "GET") {
            handleGetRequest(path);
        } else {
            sendResponse("405 Method Not Allowed", "Method Not Allowed", 405);
        }
    } catch (const std::exception &e) {
        sendResponse("500 Internal Server Error", e.what(), 500);
    }
}

void RequestHandler::handleGetRequest(const std::string &path) {
    if (path == "/") {
        sendResponse("Welcome to the server!");
    } else {
        sendResponse("404 Not Found", "Resource not found", 404);
    }
}

void RequestHandler::sendResponse(const std::string &response, const std::string &status_message, int status_code) {
    const std::string http_response =
        "HTTP/1.1 " + std::to_string(status_code) + " " + status_message + "\r\n"
        "Content-Length: " + std::to_string(response.size()) + "\r\n"
        "Content-Type: text/plain\r\n\r\n" +
        response;
    send(client_socket, http_response.c_str(), http_response.size(), 0);
}
