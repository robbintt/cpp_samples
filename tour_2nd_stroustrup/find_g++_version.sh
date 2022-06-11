#!/bin/bash

g++ -dM -E -x c++  /dev/null | grep -F __cplusplus
