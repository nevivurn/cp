#!/usr/bin/env python3

import sys
from functools import reduce

grid = []
for line in sys.stdin:
    grid.append(list(map(lambda x: x == '#', line.rstrip())))

def slope(x, y):
    i, j = x, y
    cnt = 0
    while j < len(grid):
        if grid[j][i%len(grid[j])]:
            cnt += 1
        i += x
        j += y
    return cnt

print(slope(3, 1))

