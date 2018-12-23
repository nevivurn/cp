#!/usr/bin/env python3

import sys
import re
import operator

bots = list()

for line in sys.stdin:
    m = re.search('pos=<(-?\\d+),(-?\\d+),(-?\\d+)>, r=(\\d+)', line)
    bots.append(tuple(map(int, m.groups())))

def dist(a, b):
    return sum(abs(x-y) for x,y in zip(a, b[0:3]))

max_bot = max(bots, key=operator.itemgetter(3))
print(sum(1 for bot in bots if dist(bot, max_bot) <= max_bot[3]))
