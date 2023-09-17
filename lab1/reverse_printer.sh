#!/bin/bash

count=$#

while [[ $count -gt 0 ]]
do
  echo "${!count}"
  ((count--))
done