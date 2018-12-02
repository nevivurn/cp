#!/usr/bin/env python3

import sys

thres = twos = 0

char = 'abcdefghijklmnopqrstuvwxyz'

lst = [line for line in sys.stdin]

for i in lst:
    for j in lst:
        cnt = 0
        common = []
        for a, b in zip(i, j):
            if a != b:
                cnt += 1
            else:
                common.append(a)
        if cnt == 1:
            print(''.join(common))
            break
