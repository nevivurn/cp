#!/usr/bin/env python3

import sys
import re

want = {'byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid'}

ps = ''.join(sys.stdin).split('\n\n')
cnt = 0
for p in ps:
    d = {}
    for k, v in map(lambda x: x.split(':'), p.split()):
        d[k] = v

    if 'byr' not in d or not 1920 <= int(d['byr']) <= 2002:
        continue
    if 'iyr' not in d or not 2010 <= int(d['iyr']) <= 2020:
        continue
    if 'eyr' not in d or not 2020 <= int(d['eyr']) <= 2030:
        continue
    if 'hgt' in d:
        if d['hgt'].endswith('cm'):
            if not 150 <= int(d['hgt'][:-2]) <= 193:
                continue
        elif d['hgt'].endswith('in'):
            if not 59 <= int(d['hgt'][:-2]) <= 76:
                continue
        else:
            continue
    else:
        continue
    if 'hcl' not in d or not re.match(r'^#[a-f0-9]{6}$', d['hcl']):
        continue
    if 'ecl' not in d or d['ecl'] not in {'amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth'}:
        continue
    if 'pid' not in d or not re.match(r'^[0-9]{9}$', d['pid']):
        continue
    cnt += 1
print(cnt)
