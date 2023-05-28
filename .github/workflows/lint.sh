#!/bin/bash

exit_status=0

find . -name '*.cpp' | while read -r file; do
  clang-tidy -checks='*' --warnings-as-errors='*' "$file" > /dev/null
  if [ $? -ne 0 ]; then
    echo "Linting error in $file"
    exit_status=1
  fi
done

exit $exit_status
