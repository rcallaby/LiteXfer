#include "client.h"
#include "server.h"
#include "file_handler.h"
#include <iostream>

void Client::connectAndReceive(const std::string& serverIp, int port, const std::string& outputFile) {
    FileHandler fh;
    std::cout << "[*] Connecting to server " << serverIp << ":" << port << "...\n";
    fh.startClient(serverIp, port, outputFile);
    std::cout << "[+] File received and saved as " << outputFile << "\n";
}
