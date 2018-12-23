#!/usr/bin/env python3

from itertools import product

serial = int(input())

def power(x, y):
    global serial
    return ((x+10)*y + serial) * (x+10)//100 % 10 - 5

grid = dict()
for x in range(0, 301):
    grid[(x, 0)] = 0
for y in range(1, 301):
    grid[(0, y)] = 0
for x,y in product(range(1, 301), repeat=2):
    grid[(x, y)] = grid[(x-1, y)] + grid[(x, y-1)] + power(x, y) - grid[(x-1, y-1)]

def points():
    for x,y in product(range(1, 301), repeat=2):
        for size in range(1, 302 - max(x, y)):
            yield (x,y,size)

def point_power(x, y, size):
    if size == 1:
        return power(x, y)
    return grid[(x-1, y-1)] + grid[(x+size-1, y+size-1)] - grid[(x+size-1, y-1)] - grid[(x-1, y+size-1)]

ans = max(points(), key=lambda p: point_power(*p))
print(','.join(map(str, ans)))
