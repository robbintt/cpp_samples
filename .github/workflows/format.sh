#!/bin/bash

exit_status=0

find . -name '*.cpp' -o -name '*.h' | while read -r file; do
  diff -q <(clang-format "$file") "$file" > /dev/null
  if [ $? -ne 0 ]; then
    echo "$file is not properly formatted"
    exit_status=1
  fi
done

exit $exit_status
