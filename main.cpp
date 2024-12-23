#include <iostream>
#include "server.h"

int main(int argc, char *argv[]) {
    int port = 8080;  // Default port
    if (argc == 2) {
        port = std::stoi(argv[1]);  // Port can be specified as an argument
    }

    HttpServer server(port);
    server.start();
    
    return 0;
}
