#!/usr/bin/env python3

import sys

thres = twos = 0

char = 'abcdefghijklmnopqrstuvwxyz'

for line in sys.stdin:
    a = b = False
    for c in char:
        cnt = line.count(c)
        if cnt == 2:
            a = True
        elif cnt == 3:
            b = True
    if a:
        twos += 1
    if b:
        thres += 1

print(thres*twos)
