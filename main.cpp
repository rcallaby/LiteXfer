#include <iostream>
#include <stdexcept>
#include "server.h"

int main(int argc, char *argv[]) {
    int port = 8080;  // Default port

    try {
        if (argc == 2) {
            port = std::stoi(argv[1]);  // Port can be specified as an argument
            if (port < 1 || port > 65535) {
                throw std::out_of_range("Port number must be between 1 and 65535.");
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: Invalid port number. " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Starting server on port " << port << "..." << std::endl;

    HttpServer server(port);
    server.start();

    return 0;
}
