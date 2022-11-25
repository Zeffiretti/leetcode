#!/bin/bash
# Copyright 2022 Beijing Institute of Technology
# This script formats the code in the current directory
# using clang-format. It is intended to be run from the
# root of the repository.

help() {
  sed -n 's/^# //p' "$0"
}

if [ "$1" = "-h" ] || [ "$1" = "--help" ]; then
  help
  exit 0
fi

set -ex

SCRIPT=$(readlink -f "$0")
SCRIPTPATH=$(dirname "$SCRIPT")
echo $SCRIPTPATH
format_file=$SCRIPTPATH/.clang-format
echo format file is $format_file

cd $SCRIPTPATH/
find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;
