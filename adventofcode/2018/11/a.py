#!/usr/bin/env python3

from itertools import product

serial = int(input())

def power(x, y):
    global serial
    return ((x+10)*y + serial) * (x+10)//100 % 10 - 5

def gen_three(x, y):
    for dx, dy in product([0,1,2], repeat=2):
        yield (x+dx, y+dy)

def point_power(x, y):
    return sum(power(px, py) for px, py in gen_three(x, y))

points = ((x, y) for x,y in product(range(1, 300-1), repeat=2))

print(max(points, key=lambda p: point_power(*p)))
