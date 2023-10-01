#!/bin/bash

IFS=":"
for s in $PATH; do
  printf "%s\n" "$s"
done
