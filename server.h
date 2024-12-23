#ifndef SERVER_H
#define SERVER_H

class HttpServer {
public:
    explicit HttpServer(int port);
    void start();

private:
    int port;
};

#endif
