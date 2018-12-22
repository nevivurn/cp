#!/usr/bin/env python3

import sys
import re

guard = -1

mins = dict()
start = 0

inp = sorted(list(sys.stdin))

for line in inp:
    if 'begins shift' in line:
        guard = int(re.search('#(\\d+)', line).group(1))
    if 'wakes up' in line:
        end = int(re.search(':(\\d+)', line).group(1))
        mins[guard] = mins.get(guard, 0) + end-start+1
    if 'falls asleep' in line:
        start = int(re.search(':(\\d+)', line).group(1))

bguard = sleeptime = 0
for k,v in mins.items():
    if v > sleeptime:
        bguard, sleeptime = k, v

sleeps = [0]*59
for line in inp:
    if 'begins shift' in line:
        guard = int(re.search('#(\\d+)', line).group(1))

    if guard != bguard:
        continue

    if 'wakes up' in line:
        end = int(re.search(':(\\d+)', line).group(1))
        for i in range(start, end):
            sleeps[i] += 1
    if 'falls asleep' in line:
        start = int(re.search(':(\\d+)', line).group(1))

bmin = sleepcnt = 0
for k, v in enumerate(sleeps):
    if v > sleepcnt:
        bmin, sleepcnt = k, v
print(bguard * bmin)
