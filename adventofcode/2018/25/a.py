#!/usr/bin/env python3

import sys
import re
from itertools import product
from operator import itemgetter

stars = list()
for line in sys.stdin:
    stars.append(tuple(map(int, line.strip().split(','))))

def in_bounds(bounds, point):
    for i,(lo,hi) in enumerate(bounds):
        if not (lo <= point[i] <= hi):
            return False
    return True

class QuadTree:
    def __init__(self, bounds):
        self.subs = None
        self.mine = list()
        
        self.bounds = bounds

    def in_bounds(self, point):
        return in_bounds(self.bounds, point)

    def intersect(self, bounds):
        for (alo,ahi),(blo,bhi) in zip(self.bounds, bounds):
            if not (alo <= bhi and blo <= ahi):
                return False
        return True

    def divide(self):
        subdiv = list()
        for lo,hi in self.bounds:
            if lo == hi:
                subdiv.append(((lo,hi), (lo,hi)))
            diff = (hi-lo)//2
            subdiv.append(((lo, lo+diff), (lo+diff+1, hi)))

        self.subs = list(map(QuadTree, product(*subdiv)))

    def insert(self, point):
        if not self.in_bounds(point):
            return False

        if len(self.mine) < 5:
            self.mine.append(point)
            return True

        if not self.subs:
            self.divide()

        for sub in self.subs:
            if sub.insert(point):
                return True

        assert False

    def query(self, bounds):
        points = []
        if not self.intersect(bounds):
            return points

        for point in self.mine:
            if in_bounds(bounds, point):
                points.append(point)

        if self.subs:
            for sub in self.subs:
                points.extend(sub.query(bounds))

        return points

fullbounds = tuple((min(stars, key=itemgetter(dim))[dim], max(stars, key=itemgetter(dim))[dim]) for dim in range(4))

qt = QuadTree(fullbounds)
for star in stars:
    qt.insert(star)

def dist(a, b):
    return sum(abs(x-y) for x,y in zip(a,b))

def get_bounds(point):
    return tuple((x-3, x+3) for x in point)

consts = set()
for star in stars:
    mine = {star}
    for oth in qt.query(get_bounds(star)):
        if dist(star, oth) > 3:
            continue
        mine.add(oth)
    consts.add(frozenset(mine))

for star in stars:
    cs = {c for c in consts if star in c}
    consts = {c for c in consts if c not in cs}
    cs = frozenset().union(*cs)
    consts.add(cs)

print(len(consts))
