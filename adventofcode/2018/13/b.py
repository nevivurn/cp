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

def check_rm(pos, carts):
    for cart in carts:
        if cart[:2] == pos:
            carts.remove(cart)
            return True
    return False

while True:
    if len(carts) == 1:
        print(','.join(map(str, carts[0][1::-1])))
        break

    n_carts = list()
    for cart in sorted(carts):
        if check_rm(cart[:2], n_carts):
            continue

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

        if not check_rm(pos, n_carts):
            n_carts.append((*pos, direction, crosscnt))

    carts = n_carts
