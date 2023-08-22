# Variables
CC=clang++
CFLAGS=-Isrc -Itest -Wall -std=c++20
SANITIZE_COMMON_FLAGS=-fsanitize=thread -fsanitize=undefined
ASAN_FLAGS=-fsanitize=address $(SANITIZE_COMMON_FLAGS)
MSAN_FLAGS=-fsanitize=memory $(SANITIZE_COMMON_FLAGS)
LIBS=-lm
SRCS=$(wildcard src/*.cpp)
OBJS=$(patsubst src/%.cpp, src/%.o, $(SRCS))
ASAN_OBJS=$(patsubst src/%.cpp, src/%.asan.o, $(SRCS))
MSAN_OBJS=$(patsubst src/%.cpp, src/%.msan.o, $(SRCS))
TEST_SRCS=$(wildcard test/*.cpp)
TEST_OBJS=$(patsubst test/%.cpp, test/%.o, $(TEST_SRCS))

# Default rule
src/%.o: src/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

# Test rule
test/%.o: test/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

# ASan objects (lsan included)
src/%.asan.o: src/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -fsanitize=address

# MSan objects
src/%.msan.o: src/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -fsanitize=memory

# TSan objects
src/%.tsan.o: src/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -fsanitize=thread

# UBSan objects
src/%.ubsan.o: src/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -fsanitize=undefined

# Main program
my_program: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# ASan Tests (lsan included)
my_tests_asan: $(TEST_OBJS) $(filter-out src/main.asan.o, $(ASAN_OBJS))
	$(CC) -o $@ $^ $(CFLAGS) -fsanitize=address $(LIBS)

# MSan Tests
my_tests_msan: $(TEST_OBJS) $(filter-out src/main.msan.o, $(MSAN_OBJS))
	$(CC) -o $@ $^ $(CFLAGS) -fsanitize=memory $(LIBS)

# TSan Tests
my_tests_tsan: $(TEST_OBJS) $(filter-out src/main.tsan.o, $(TSAN_OBJS))
	$(CC) -o $@ $^ $(CFLAGS) -fsanitize=thread $(LIBS)

# UBSan Tests
my_tests_ubsan: $(TEST_OBJS) $(filter-out src/main.ubsan.o, $(UBSAN_OBJS))
	$(CC) -o $@ $^ $(CFLAGS) -fsanitize=undefined $(LIBS)


# Tests
my_tests: $(TEST_OBJS) $(filter-out src/main.o, $(OBJS))
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

my_sans: my_tests_asan my_tests_msan my_tests_tsan my_tests_ubsan

.PHONY: clean

clean:
	rm -f src/*.asan.o src/*.msan.o
	rm -f src/*.o test/*.o my_program my_tests my_tests_asan my_tests_msan my_tests_ubsan my_tests_tsan
