#!/usr/bin/env python3

import sys

nums = list(map(int, sys.stdin.readline().rstrip().split(',')))
seen= dict()
for i, num in enumerate(nums):
    seen[num] = i

while len(nums) < 30000000:
    num = nums[-1]

    if num not in seen:
        nxt = 0
    else:
        nxt = len(nums) - seen[num] -1

    seen[nums[-1]] = len(nums)-1
    nums.append(nxt)

print(nums[-1])
