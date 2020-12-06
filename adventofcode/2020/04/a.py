#!/usr/bin/env python3

import sys

want = {'byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid'}

ps = ''.join(sys.stdin).split('\n\n')
cnt = 0
for p in ps:
    d = {}
    for k, v in map(lambda x: x.split(':'), p.split()):
        d[k] = v
    if d.keys() & want == want:
        cnt += 1
print(cnt)
