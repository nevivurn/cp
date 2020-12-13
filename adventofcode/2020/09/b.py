#!/usr/bin/env python3

import sys

nums = [int(line.rstrip()) for line in sys.stdin]

cums = [0]
for num in nums:
    cums.append(cums[-1] + num)

target = 0
for i, cur in enumerate(nums):
    if i < 25:
        continue

    curs = nums[i-25:i]
    for j, a in enumerate(curs):
        for b in curs[j+1:]:
            if a+b == cur:
                break
        else:
            continue
        break
    else:
        target = cur
        break

i, j = 0, 0
while True:
    cur = cums[j] - cums[i]
    if cur < target:
        j += 1
    elif cur > target:
        i += 1
    else:
        break

print(max(nums[i:j]) + min(nums[i:j]))
