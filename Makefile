CXX = g++
CXXFLAGS = -std=c++11 -Wall -I/usr/include/gtest -pthread
LDFLAGS = -lgtest -lgtest_main -pthread

SRCS = main.cpp server.cpp request_handler.cpp file_handler.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = litexfer

TEST_SRCS = tests/test_main.cpp tests/test_request_handler.cpp tests/test_file_handler.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
TEST_EXEC = test_litexfer

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

test: $(TEST_OBJS) $(OBJS)
	$(CXX) $(TEST_OBJS) $(OBJS) -o $(TEST_EXEC) $(LDFLAGS)
	./$(TEST_EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC) $(TEST_OBJS) $(TEST_EXEC)

