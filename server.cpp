#include "server.h"
#include "request_handler.h"
#include "file_handler.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

HttpServer::HttpServer(int port) : port(port) {}

void HttpServer::start() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Error creating socket");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        return;
    }

    // Listen for incoming connections
    if (listen(server_sock, 10) < 0) {
        perror("Error listening on socket");
        return;
    }

    std::cout << "Server started on port " << port << "...\n";

    // Main server loop
    while (true) {
        addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);
        if (client_sock < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Create a request handler
        RequestHandler *handler = new FileHandler(client_sock);
        handler->handleRequest();
        delete handler;
    }

    close(server_sock);
}
