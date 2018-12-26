#!/usr/bin/env python3

import sys
from itertools import chain

grid = list(list(line) for line in sys.stdin)

dirmap = {'^': 0, '>': 1, 'v': 2, '<': 3}
dirdiff = [(-1, 0), (0, 1), (1, 0), (0, -1)]
crossmap = [-1, 0, 1]

carts = list()
for y,line in enumerate(grid):
    for x,char in enumerate(line):
        if char in dirmap:
            carts.append((y, x, dirmap[char], 0))

            if dirmap[char]%2 == 0:
                grid[y][x] = '|'
            else:
                grid[y][x] = '-'

while True:
    n_carts = list()

    for cart in sorted(carts):
        char = grid[cart[0]][cart[1]]

        direction = cart[2]
        crosscnt = cart[3]
        if char == '/':
            direction ^= 0x1
        elif char == '\\':
            direction ^= 0x3
        elif char == '+':
            direction = (direction+crossmap[crosscnt]) % 4
            crosscnt = (crosscnt+1)%3

        pos = tuple(a+b for a,b in zip(cart, dirdiff[direction]))

        if any(c[:2] == pos for c in chain(carts, n_carts)):
            print(','.join(map(str, reversed(pos))))
            break

        n_carts.append((*pos, direction, crosscnt))
    else:
        carts = n_carts
        continue
    break
