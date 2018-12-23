#!/usr/bin/env python3

import re

players, points = re.search('(\\d+) players; last marble is worth (\\d+) points', input()).groups()

print(players, points)

players = [0]*int(players)
points = int(points)

marbles = [0]
cur = 0
for i in range(1, points+1):
    if i%23 == 0:
        ind = (cur-7)%len(marbles)
        players[i%len(players)] += i + marbles.pop(ind)
        cur = ind
    else:
        ind  = (cur+2)%len(marbles)
        marbles.insert(ind, i)
        cur = ind

print(max(players))
