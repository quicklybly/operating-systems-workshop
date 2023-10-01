#!/bin/bash

declare path

rec() {
  if [[ $# -lt 2 ]]; then
    echo "Usage: rec <path> <start_depth_level>"
    return 1
  fi
  level=$2
  for item in "$1/"*; do
    if [[ -f $item ]]; then
      echo "$level) $(realpath "$item")"
    elif [[ -d $item ]]; then
      echo "$level) $(realpath "$item")"
      ((level++))
      rec "$item" "$level"
      ((level--))
    else continue
    fi
  done
}

if [[ $# -eq 1 ]]; then
  path=$1
else path=$(pwd)
fi

rec "$path" 1

