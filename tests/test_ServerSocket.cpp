#include <gtest/gtest.h>
#include "../src/ServerSocket.hpp"

class ServerSocketTest : public ::testing::Test {
protected:
    ServerSocket* server;

    void SetUp() override {
        server = new ServerSocket();
    }

    void TearDown() override {
        delete server;
    }
};

// Test binding and listening
TEST_F(ServerSocketTest, BindAndListen) {
    ASSERT_TRUE(server->bind(8081));  // Use a different port to avoid conflicts
    ASSERT_TRUE(server->listen(5));
}

// Test accepting a connection (requires a client connection)
TEST_F(ServerSocketTest, AcceptConnection) {
    ASSERT_TRUE(server->bind(8081));
    ASSERT_TRUE(server->listen(5));

    // Simulate a client connection in a separate thread or use a timeout
    Socket client;
    client.connect("127.0.0.1", 8081);

    Socket* accepted = server->accept();
    ASSERT_NE(accepted, nullptr);
    ASSERT_TRUE(accepted->is_valid());
    delete accepted;
}