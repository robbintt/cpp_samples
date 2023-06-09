#!/bin/bash

set -ex

cd gpt4
if [ -f "CMakeLists.txt" ]; then
  cmake .
  make my_program
  make my_tests
else
  make my_program
  make my_tests
  #clang++ -std=c++17 -O3 -Wall -Wextra -o main *.cpp
fi
./my_program
./my_tests
