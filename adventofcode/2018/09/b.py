#!/usr/bin/env python3

import re
from collections import deque

players, points = re.search('(\\d+) players; last marble is worth (\\d+) points', input()).groups()

players = [0]*int(players)
points = int(points)*100

marbles = deque([0])
cur = 0
for i in range(1, points+1):
    if i%23 == 0:
        marbles.rotate(7)
        players[i%len(players)] += i + marbles.popleft()
    else:
        marbles.rotate(-2)
        marbles.appendleft(i)

print(max(players))
