#!/usr/bin/env python3

import sys

nums = list(sorted([0] + [int(line.rstrip()) for line in sys.stdin]))
nums.append(nums[-1] + 3)
diffs = [0] * 4

for i, n in enumerate(nums):
    if i == 0:
        continue
    diffs[n-nums[i-1]] += 1

print(diffs[1] * diffs[3])
