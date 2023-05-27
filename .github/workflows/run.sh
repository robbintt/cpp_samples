#!/bin/bash

cd gpt4
if [ -f "CMakeLists.txt" ]; then
  cmake .
  make
else
  make
  #clang++ -std=c++17 -O3 -Wall -Wextra -o main *.cpp
fi
./fibonacci 
