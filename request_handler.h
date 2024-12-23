#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

#include <string>

class RequestHandler {
protected:
    int client_socket;

public:
    explicit RequestHandler(int client_sock);
    virtual ~RequestHandler();

    virtual void handleRequest();
    virtual void handleGetRequest();

protected:
    void sendResponse(const std::string &response);
};

#endif // REQUEST_HANDLER_H

