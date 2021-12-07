#!/usr/bin/env python3

l = list(sorted(map(int, input().split(','))))

def dists(cur):
    s = 0
    for c in l:
        d = abs(c-cur)
        s += int((d+1) * (d/2))
    return s

c = min(range(l[0], l[-1]+1), key=dists)
print(dists(c))
