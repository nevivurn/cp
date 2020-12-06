#!/usr/bin/env python3

import sys

nums = list(map(int, sys.stdin))

for i, a in enumerate(nums):
    for j, b in enumerate(nums[i+1:]):
        for k, c in enumerate(nums[j+1:]):
            if a+b+c == 2020:
                print(a*b*c)
