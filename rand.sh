#!/bin/bash

# check if an argument was provided
if [[ $# -eq 0 ]]; then
  echo "Error: please provide a number as an argument."
  exit 1
fi

# get the number from the first argument
n=$1
range=32767
if [[ ! -z $2 ]]; then
  range=$2
fi

# generate n random numbers separated by spaces
result=""
generated=()
while [[ ${#generated[@]} -lt $n ]]; do
  num=$(( $RANDOM % $range - $range / 2 ))
  if [[ ! " ${generated[@]} " =~ " ${num} " ]]; then
    generated+=($num)
    result="$result $num"
  fi
done

# output the result
echo $result