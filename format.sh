#!/bin/bash
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

cd $SCRIPTPATH
format_dir(){
  for file in `ls -a $1`
    do
      if [ -d $1"/"$file ];  then
        if [[ $file != '.' && $file != '..' && $file != 'build' && ! $file =~ ^\. ]];  then
            format_dir $1"/"$file
        fi
      else
        file=$1"/"$file
        if [[ $file =~ ^/[a-zA-Z].*\.(h|cc|cpp)$ ]];  then
          clang-format -i $file --style=file
        fi
      fi
  done
}
cd $SCRIPTPATH
format_dir $SCRIPTPATH
