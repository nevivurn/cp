#!/usr/bin/env python3

import sys

cnt = 0
for line in sys.stdin:
    p, pw = line.split(': ')
    pc, pl = p.split()
    lo, hi = map(int, pc.split('-'))
    if (pw[lo-1] == pl) ^ (pw[hi-1] == pl):
        cnt += 1
print(cnt)
