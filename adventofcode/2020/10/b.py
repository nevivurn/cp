#!/usr/bin/env python3

import sys

nums = list(sorted([0] + [int(line.rstrip()) for line in sys.stdin]))
nums.append(nums[-1] + 3)

dp = [1]
while len(dp) < len(nums):
    cur = len(dp)
    i = cur-1
    cum = 0
    while i >= 0 and nums[cur]-nums[i] <= 3:
        cum += dp[i]
        i -= 1
    dp.append(cum)


print(dp[-1])
