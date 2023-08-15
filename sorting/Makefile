# Variables
#CC=g++
# move to LLVM
CC=clang++
CFLAGS=-Isrc -Itest -Wall -std=c++20
LIBS=-lm
SRCS=$(wildcard src/*.cpp)
OBJS=$(patsubst src/%.cpp, src/%.o, $(SRCS))
TEST_SRCS=$(wildcard test/*.cpp)
TEST_OBJS=$(patsubst test/%.cpp, test/%.o, $(TEST_SRCS))

# Default rule
src/%.o: src/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

# Main program
my_program: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Test rule
test/%.o: test/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

# Tests
my_tests: $(TEST_OBJS) $(filter-out src/main.o, $(OBJS))
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f src/*.o test/*.o my_program my_tests
