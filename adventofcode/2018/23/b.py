#!/usr/bin/env python3

# Based heavily off of https://gist.github.com/n3o59hf/5d9790418e200fd99edcef2cdfa699b0

import sys
import re
import operator
import itertools

bots = list()

for line in sys.stdin:
    m = re.search('pos=<(-?\\d+),(-?\\d+),(-?\\d+)>, r=(\\d+)', line)
    bots.append(tuple(map(int, m.groups())))

def dist(a, b):
    return sum(abs(x-y) for x,y in zip(a, b[0:3]))

def delta(bots, op):
    ls = [op(bot) for bot in bots]
    return max(ls)-min(ls)

def gen_points(point, radius):
    for diff in itertools.product([-1, 0, 1], repeat=3):
        yield tuple(p + d*radius for p,d in zip(point, diff))

radius = max(delta(bots, operator.itemgetter(d)) for d in range(3))

points = [(0, 0, 0)]
while radius:
    radius = radius+1 if radius>2 else radius
    radius = radius//2

    n_points = dict()
    for point in points:
        for n_point in gen_points(point, radius):
            cnt = sum(1 for bot in bots if dist(bot, n_point) <= radius+bot[3])
            n_points[n_point] = cnt

    max_cnt = max(n_points.values())
    points = (pt for pt,cnt in n_points.items() if cnt == max_cnt)

print(min(map(lambda p: dist((0,0,0), p), points)))
