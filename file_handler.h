#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "request_handler.h"

class FileHandler : public RequestHandler {
public:
    explicit FileHandler(int client_sock);
    void handleGetRequest() override;
};

#endif
