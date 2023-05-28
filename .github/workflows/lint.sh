#!/bin/bash

exit_status=0

# Generate the compile_commands.json file
if [ ! -d build ]; then
  mkdir build
fi
cmake -Bbuild -H.
cmake --build build
ln -sf build/compile_commands.json compile_commands.json

# Check if compile_commands.json exists
if [ ! -f ./compile_commands.json ]; then
  echo "Error: compile_commands.json not found. Generation failed."
  exit 1
fi

find . -name '*.cpp' | while read -r file; do
  clang_tidy_output=$(clang-tidy -p=./compile_commands.json --checks='*' --warnings-as-errors='*' "$file")
  if [ $? -ne 0 ]; then
    echo "Linting error in $file:"
    echo "$clang_tidy_output"
    echo ""
    exit_status=1
  fi
done

exit $exit_status
