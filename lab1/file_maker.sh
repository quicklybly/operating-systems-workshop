#!/bin/bash

if [[ $# -eq 0 ]]
then
  echo "Usage: file_maker <name> [<mode>]"
  exit 2
elif [[ -e $1 ]]
then
  echo "File $(pwd)/$1  already exists"
  exit 2
fi

touch "$1"

if [[ $# -ge 2 ]]
then
  if ! chmod "$2" "$1" 2> /dev/null;
  then
    echo "Invalid mode $2, consider using chmod style"
    rm "$1"
    exit 2
  fi
fi