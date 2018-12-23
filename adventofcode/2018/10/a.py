#!/usr/bin/env python3

import sys
import re
import operator

points = []
for line in sys.stdin:
    pos = tuple(map(int, [line[10:16], line[18:24]]))
    vel = tuple(map(int, [line[36:38], line[40:42]]))
    points.append((pos, vel))

for i in range(100000):
    cur_points = [(pos[0]+vel[0]*i, pos[1]+vel[1]*i) for pos,vel in points]

    xmax = max(cur_points, key=operator.itemgetter(0))
    xmin = min(cur_points, key=operator.itemgetter(0))
    ymax = max(cur_points, key=operator.itemgetter(1))
    ymin = min(cur_points, key=operator.itemgetter(1))

    if (xmax[0]-xmin[0]) * (ymax[1]-ymin[1]) < 100*100:
        print(i)
        for y in range(ymin[1], ymax[1]+1):
            for x in range(xmin[0], xmax[0]+1):
                if (x, y) in cur_points:
                    print('.', end='')
                else:
                    print('#', end='')
            print()
        print()
