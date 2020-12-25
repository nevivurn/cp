#!/usr/bin/env python3

import sys

d = dict()

fmask = 0
tmask = 0

for line in sys.stdin:
    lhs, _, rhs = line.rstrip().split()
    if lhs == 'mask':
        fmask = int(rhs.replace('X', '1'), base=2)
        tmask = int(rhs.replace('X', '0'), base=2)
    else:
        addr = int(lhs[4:-1])
        num = int(rhs)
        d[addr] = num & fmask | tmask

print(sum(d.values()))
