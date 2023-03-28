#!/bin/bash

# Define the executable to run
EXECUTABLE="./push_swap"

# Define the set of numbers to permute
NUMBERS=(1 2 3 4 5)

# Check if an argument was passed
if [ $# -eq 0 ]; then
	echo "Error: Please provide a value for n"
	exit 1
fi

# Read the argument into a variable
n=$1

# Create an array containing numbers 1 to n
NUMBERS=""
for (( i=1; i<=n; i++ )); do
	NUMBERS+=$i
done

function swap() {
	local string=$1
	local len=${#string}
	local from=$2
	local to=$3
	local i=0
	local s=""
	while [[ $i -lt $len ]]; do
		if [[ $i -eq $from ]]; then
			s=$s${string:$to:1}
		elif [[ $i -eq $to ]]; then
			s=$s${string:$from:1}
		else
			s=$s${string:$i:1}
		fi
		i=$(($i+1))
	done
	echo $s
}

max=0
function perm() {
	local string=$1
	local len=${#string}
	local idx=$2
	if [[ $idx -ge $len ]]; then
		digits=()
		for (( i=0; i<${#string}; i++ )); do
			digits+=("${string:$i:1}")
		done
		echo $EXECUTABLE "${digits[@]}"
		ops=$($EXECUTABLE "${digits[@]}" | wc -l)
		printf '%8s\n' $ops
		num=$((ops))
		max=$(( ops > max ? num : max ))
	else
		local i=$idx
		while [[ $i -lt $len ]]; do
			perm $(swap $string $i $idx) $((idx+1))
			i=$((i+1))
		done
	fi
}

# Call the generate_permutations function with the initial array
perm $NUMBERS
echo
echo "max ops:" $max
echo