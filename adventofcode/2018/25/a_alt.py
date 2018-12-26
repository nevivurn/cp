#!/usr/bin/env python3

import sys

stars = {tuple(map(int, line.split(','))) for line in sys.stdin}

def dist(a, b):
    return sum(abs(x-y) for x,y in zip(a,b))

consts = 0
while len(stars):
    added = {stars.pop()}
    consts += 1

    while len(added):
        n_added = set()

        for start in added:
            this_added = {s for s in stars if dist(start, s) <= 3}
            stars -= this_added
            n_added.update(this_added)

        added = n_added
print(consts)
