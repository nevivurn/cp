#!/usr/bin/env python3

import sys

grid = [False]*(128*8)
for line in sys.stdin:
    s = line.rstrip().replace('B', '1').replace('F', '0').replace('L', '0').replace('R', '1')
    s = int(s, 2)
    grid[s] = True
for i, v in enumerate(grid):
    if not grid[i] and grid[i+1]:
        print(i)
