#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    void connectAndReceive(const std::string& serverIp, int port, const std::string& outputFile);
};

#endif
