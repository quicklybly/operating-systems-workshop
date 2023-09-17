#!/bin/bash

if [[ ! $# -eq 3 ]]
then
  echo "Usage: dummy_calculator <A> <+|-|*|/> <B>"
  exit 2
fi

# never use expr in production code, use (()) instead
case "$2" in
    '+'|'-'|'*')
      echo "$(expr "$1" "$2" "$3")"
    ;;
    '/')
      if [[ $3 -eq 0 ]]
      then
        echo "Division by 0 not allowed"
        exit 2
      else
        echo "$(expr "$1" "$2" "$3")"
      fi
    ;;
    *)
      echo "Unknown operator: $2, consider using <+|-|*|/>"
      exit 2
    ;;
esac