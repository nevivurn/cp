#!/usr/bin/env python3

import sys

ans = 0
cur = set()
for line in sys.stdin:
    if len(line) == 1:
        ans += len(cur)
        cur = set()
        continue
    cur |= set(line.rstrip())
ans += len(cur)
print(ans)
