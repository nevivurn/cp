#!/usr/bin/env python3

import sys

ans = 0
cur = None
for line in sys.stdin:
    if len(line) == 1:
        ans += len(cur)
        cur = None
        continue
    if cur is None:
        cur = set(line.rstrip())
    else:
        cur &= set(line.rstrip())
ans += len(cur)
print(ans)
