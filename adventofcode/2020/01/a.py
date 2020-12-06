#!/usr/bin/env python3

import sys

nums = list(map(int, sys.stdin))

for i, a in enumerate(nums):
    for b in nums[i+1:]:
        if a+b == 2020:
            print(a*b)
