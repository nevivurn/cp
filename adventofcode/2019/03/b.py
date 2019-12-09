#!/usr/bin/env python3

wire1 = input().split(',')
wire2 = input().split(',')

def get_set(steps):
    cur = (0, 0)
    seen = {}

    total = 0
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
            total += 1
            cur = (cur[0]+diff[0], cur[1]+diff[1])
            if cur not in seen:
                seen[cur] = total
    return seen

aseen = get_set(wire1)
bseen = get_set(wire2)
cross = aseen.keys() & bseen.keys()
print(min(map(lambda p: aseen[p]+bseen[p], cross)))
