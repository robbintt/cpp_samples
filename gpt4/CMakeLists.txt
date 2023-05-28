# gpt-4 generated this based on the adjacent Makefile

cmake_minimum_required(VERSION 3.20)
project(my_program LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

add_executable(my_program ${SOURCES})
target_include_directories(my_program PRIVATE src test)
target_compile_options(my_program PRIVATE -Wall)
target_link_libraries(my_program PRIVATE m)

# Create a test executable, excluding the main.cpp from the sources
add_executable(my_tests ${TEST_SOURCES} ${SOURCES})
list(FILTER SOURCES EXCLUDE REGEX "src/main.cpp")
target_include_directories(my_tests PRIVATE src test)
target_compile_options(my_tests PRIVATE -Wall)
target_link_libraries(my_tests PRIVATE m)
