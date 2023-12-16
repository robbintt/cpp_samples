# Variables
#CC=g++ -std=c++20
# worked, but 5.7 MB
#CC=mips-unknown-linux-musl-g++ -static -std=c++20
# Bus Error:
#CC=mips-unknown-linux-musl-g++ -std=c++20
# try only static linking libstdc++
# success, but only saved 100k
#CC=mips-unknown-linux-musl-g++ -std=c++20 -static-libstdc++
# now we need to dynamic link all with gcc older version
# no more support for c++20
CC=mips-unknown-linux-musl-g++ -std=c++17
# move to LLVM
##CC=clang++ -stdlib=libstdc++
# use mips
#CC=clang++ -std=c++20
#CFLAGS=-Isrc -Itest -Wall -Os
CFLAGS=-Isrc -Itest -Wall -Os
LDFLAGS=-Wl,--dynamic-linker,/lib/ld-musl-mips-sf.so.1
#CFLAGS=-Isrc -Itest -Wall -std=c++20 -O3 -S -target mips -mcpu=mips32
LIBS=-lm
SRCS=$(wildcard src/*.cpp)
OBJS=$(patsubst src/%.cpp, src/%.o, $(SRCS))
TEST_SRCS=$(wildcard test/*.cpp)
TEST_OBJS=$(patsubst test/%.cpp, test/%.o, $(TEST_SRCS))

# Default rule
src/%.o: src/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

# Main program
my_program: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LDFLAGS)


# Test rule
test/%.o: test/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

# Tests
my_tests: $(TEST_OBJS) $(filter-out src/main.o, $(OBJS))
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f src/*.o test/*.o my_program my_tests
