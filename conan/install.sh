#!/bin/bash

# This script will also reinstall.

set -ex

PROJECT=conan
VIRTUALENV_DIR=$HOME/virtualenvs/$PROJECT

mkdir -p $HOME/virtualenvs

set +e
rm -rI $VIRTUALENV_DIR
set -e

virtualenv $VIRTUALENV_DIR
source $VIRTUALENV_DIR/bin/activate

pip install -r requirements.txt
