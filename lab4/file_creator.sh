#!/bin/bash

filename="${1:-cool_new_file}"

trap 'echo "File already exists"' ERR

[[ ! -f "$filename" ]] && touch "$filename" || pkill ERR