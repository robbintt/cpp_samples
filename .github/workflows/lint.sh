#!/bin/bash

exit_status=0

cd gpt4

# Generate the compile_commands.json file
# will this exit 1 if it doesn't make the file?
make clean
bear --output compile_commands.json -- make my_program my_tests


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
