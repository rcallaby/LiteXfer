#include <gtest/gtest.h>
#include "../src/HTTPRequest.hpp"

class HTTPRequestTest : public ::testing::Test {
protected:
    HTTPRequest* request;

    void SetUp() override {
        request = new HTTPRequest(nullptr);  // Null socket for parsing tests
    }

    void TearDown() override {
        delete request;
    }
};

// Test parsing a simple GET request
TEST_F(HTTPRequestTest, ParseGetRequest) {
    std::string raw_request = "GET /index.html HTTP/1.1\r\nHost: localhost\r\n\r\n";
    request->parse(raw_request);

    ASSERT_EQ(request->get_method(), "GET");
    ASSERT_EQ(request->get_path(), "/index.html");
    ASSERT_EQ(request->get_version(), "HTTP/1.1");
    ASSERT_EQ(request->get_header("Host"), "localhost");
}

// Test generating a response
TEST_F(HTTPRequestTest, GenerateResponse) {
    std::string raw_request = "GET /index.html HTTP/1.1\r\nHost: localhost\r\n\r\n";
    request->parse(raw_request);

    std::string response = request->generate_response("Hello, World!", 200);
    std::string expected = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
    ASSERT_EQ(response, expected);
}

// Test handling invalid request
TEST_F(HTTPRequestTest, HandleInvalidRequest) {
    std::string raw_request = "INVALID REQUEST\r\n";
    request->parse(raw_request);

    std::string response = request->generate_response("Bad Request", 400);
    std::string expected = "HTTP/1.1 400 Bad Request\r\nContent-Length: 11\r\n\r\nBad Request";
    ASSERT_EQ(response, expected);
}