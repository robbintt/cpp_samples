#!/bin/bash

#docker build -t cpp_samples_test -f Dockerfile.test .

# cache base
docker build -t my_base_image --target=base -f Dockerfile.test .
docker build -t my_container --cache-from=my_base_image -f Dockerfile.test .

docker run --rm cpp_samples_test
