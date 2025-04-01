#include <gtest/gtest.h>
#include "../src/Socket.hpp"

class SocketTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code, if needed (e.g., create a mock server for testing)
    }

    void TearDown() override {
        // Cleanup code, if needed
    }
};

// Test Socket creation and closure
TEST_F(SocketTest, CreateAndCloseSocket) {
    Socket sock;
    ASSERT_FALSE(sock.is_valid());  // Initially invalid
    // Note: Actual connection would require a server, so we test basic state here
}

// Test sending data (requires a mock or loopback server)
TEST_F(SocketTest, SendData) {
    Socket sock;
    sock.connect("127.0.0.1", 8080);  // Assumes a server is running locally
    if (sock.is_valid()) {
        std::string data = "GET / HTTP/1.1\r\n\r\n";
        int bytes_sent = sock.send(data.c_str(), data.size());
        ASSERT_GT(bytes_sent, 0);
    } else {
        GTEST_SKIP() << "Skipping send test due to no server connection";
    }
}

// Test receiving data
TEST_F(SocketTest, ReceiveData) {
    Socket sock;
    sock.connect("127.0.0.1", 8080);
    if (sock.is_valid()) {
        char buffer[1024];
        int bytes_received = sock.receive(buffer, sizeof(buffer));
        ASSERT_GT(bytes_received, 0);
        ASSERT_NE(std::string(buffer, bytes_received), "");
    } else {
        GTEST_SKIP() << "Skipping receive test due to no server connection";
    }
}