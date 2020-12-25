#!/usr/bin/env python3

import sys

ts = int(sys.stdin.readline().rstrip())
buses = sys.stdin.readline().rstrip().split(',')
buses = list(map(int, filter(lambda x: x != 'x', buses)))

time = min(map(lambda x: x*((ts+x-1)//x) - ts, buses))
ans = next(filter(lambda x: time == (x*((ts+x-1)//x) - ts), buses))

print(ans * time)
