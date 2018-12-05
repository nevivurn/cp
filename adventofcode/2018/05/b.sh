#!/usr/bin/env bash

./a > out

for x in {a..z}; do
	echo $(cat out | tr -d "$x${x^}" | ./a | wc -c) $x
done | sort -n | head -n1

rm out
