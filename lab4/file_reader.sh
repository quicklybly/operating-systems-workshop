#!/bin/bash


if [[ ! $# -eq 1 ]]
then
  echo "Usage: dummy_reader <filename>"
  exit 2
fi

exec 3<&1
exec < "$1"

while IFS=$'\n' read -r line || [[ -n "$line" ]]; do
  echo "$line"
done

exec <&3 3<&-
