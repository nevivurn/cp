#!/usr/bin/env python3

import sys
import re

init = '##.#.#.##..#....######..#..#...#.#..#.#.#..###.#.#.#..#..###.##.#..#.##.##.#.####..##...##..#..##.#.'

grid = {i for i,c in enumerate(init) if c == '#'}

rules = dict()
for line in sys.stdin:
    m = re.search('(.{5}) => (.)', line)

    pat = tuple(map(lambda c: c == '#', m.group(1)))
    out = m.group(2) == '#'
    rules[pat] = out

n_grid = grid.copy()
for i in range(100):
    grid = n_grid
    n_grid = set()

    for x in sorted(grid):
        for xp in range(x-2, x+3):
            if rules[tuple(i in grid for i in range(xp-2, xp+3))]:
                n_grid.add(xp)

left = 50000000000-100
diff = sum(n_grid)-sum(grid)
print(left*diff + sum(n_grid))
