#!/usr/bin/env python3

import sys

nums = []
for line in sys.stdin:
    cur = int(line.rstrip())

    if len(nums) < 25:
        nums.append(cur)
        continue

    curs = nums[-25:]
    for i, a in enumerate(curs):
        for b in curs[i+1:]:
            if a+b == cur:
                break
        else:
            continue
        break
    else:
        print(cur)
        break

    nums.append(cur)
