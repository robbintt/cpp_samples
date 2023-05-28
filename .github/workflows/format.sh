#!/bin/bash

exit_status=0

find . -name '*.cpp' -o -name '*.h' | while read -r file; do
  diff_output=$(diff -u <(clang-format "$file") "$file")
  if [ $? -ne 0 ]; then
    echo "Formatting issues in $file:"
    echo "$diff_output"
    echo ""
    exit_status=1
  fi
done

exit $exit_status

