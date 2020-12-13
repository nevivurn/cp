#!/usr/bin/env python3

import sys

grid = []
occupied = []
for line in sys.stdin:
    line = line.rstrip()
    line = list(map(lambda x: x == 'L', line))
    grid.append(line)
    occupied.append([False] * len(line))

while True:
    changed = False

    step = []
    for y in range(len(grid)):
        step.append(occupied[y].copy())

        for x in range(len(grid[y])):
            if not grid[y][x]:
                continue

            cnt = 0
            for i in [x-1, x, x+1]:
                for j in [y-1, y, y+1]:
                    if i == x and j == y:
                        continue
                    if i < 0 or i >= len(grid[y]) or j < 0 or j >= len(grid):
                        continue
                    if occupied[j][i]:
                        cnt += 1
            if not occupied[y][x] and cnt == 0:
                step[y][x] = True
                changed = True
            elif occupied[y][x] and cnt >= 4:
                step[y][x] = False
                changed = True
    if not changed:
        break

    occupied = step

print(sum(r.count(True) for r in occupied))
