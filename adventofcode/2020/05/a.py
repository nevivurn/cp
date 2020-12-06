#!/usr/bin/env python3

import sys

grid = [False]*(128*8)
ans = -1
for line in sys.stdin:
    s = line.rstrip().replace('B', '1').replace('F', '0').replace('L', '0').replace('R', '1')
    s = int(s, 2)
    ans = max(s, ans)
print(ans)
