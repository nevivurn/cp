#!/usr/bin/env python3

wire1 = input().split(',')
wire2 = input().split(',')

def get_set(steps):
    cur = (0, 0)
    seen = set()
    for step in steps:
        if step[0] == 'L':
            diff = (-1, 0)
        if step[0] == 'R':
            diff = (1, 0)
        if step[0] == 'D':
            diff = (0, -1)
        if step[0] == 'U':
            diff = (0, 1)

        cnt = int(step[1:])
        for i in range(cnt):
            cur = (cur[0]+diff[0], cur[1]+diff[1])
            seen.add(cur)
    return seen

cross = get_set(wire1) & get_set(wire2)
print(min(map(lambda p: abs(p[0])+abs(p[1]), cross)))
