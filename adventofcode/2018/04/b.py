#!/usr/bin/env python3

import sys
import re

inp = sorted(list(sys.stdin))
guards = set()

for line in inp:
    if 'begins shift' in line:
        guard = int(re.search('#(\\d+)', line).group(1))
        guards.add(guard)

bguard = bmin = 0
cnt = 0

for curguard in guards:
    sleeps = [0]*59
    for line in inp:
        if 'begins shift' in line:
            guard = int(re.search('#(\\d+)', line).group(1))
    
        if guard != curguard:
            continue
    
        if 'wakes up' in line:
            end = int(re.search(':(\\d+)', line).group(1))
            for i in range(start, end):
                sleeps[i] += 1
        if 'falls asleep' in line:
            start = int(re.search(':(\\d+)', line).group(1))
    
    best_minute = max_times = 0
    for k, v in enumerate(sleeps):
        if v > max_times:
            best_minute, max_times = k, v
    if max_times > cnt:
        bguard, bmin, cnt = curguard, best_minute, max_times

print(bguard * bmin)
