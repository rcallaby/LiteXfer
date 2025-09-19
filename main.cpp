#include <iostream>
#include <string>
#include "file_handler.h"

void printUsage() {
    std::cout << "LiteXfer - Lightweight File Transfer Tool\n\n";
    std::cout << "Usage:\n";
    std::cout << "  Run as server (send file):\n";
    std::cout << "    ./litexfer --server <file_to_send> <port>\n\n";
    std::cout << "  Run as client (receive file):\n";
    std::cout << "    ./litexfer --client <server_ip> <port> <output_file>\n\n";
    std::cout << "Examples:\n";
    std::cout << "  ./litexfer --server test.txt 8080\n";
    std::cout << "  ./litexfer --client 127.0.0.1 8080 received.txt\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 1;
    }

    std::string mode = argv[1];
    FileHandler fh;

    if (mode == "--server") {
        if (argc != 4) {
            std::cerr << "Error: Invalid arguments for server mode.\n";
            printUsage();
            return 1;
        }
        std::string filename = argv[2];
        int port = std::stoi(argv[3]);
        fh.startServer(filename, port);

    } else if (mode == "--client") {
        if (argc != 5) {
            std::cerr << "Error: Invalid arguments for client mode.\n";
            printUsage();
            return 1;
        }
        std::string serverIp = argv[2];
        int port = std::stoi(argv[3]);
        std::string outputFile = argv[4];
        fh.startClient(serverIp, port, outputFile);

    } else {
        std::cerr << "Error: Unknown mode.\n";
        printUsage();
        return 1;
    }

    return 0;
}


