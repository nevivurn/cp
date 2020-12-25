#!/usr/bin/env python3

import sys

import gmpy2

sys.stdin.readline()
nums = sys.stdin.readline().split(',')

N = 1
for n in nums:
    if n == 'x':
        continue
    N *= int(n)

x = 0
for a, n in enumerate(nums):
    if n == 'x':
        continue
    n = int(n)
    a = (n-a)%n

    Ni = N // n
    _, M, _ = gmpy2.gcdext(Ni, n)
    x += a * M * Ni

print(x%N)
