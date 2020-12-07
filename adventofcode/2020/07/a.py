#!/usr/bin/env python3

import sys

rules = {}
for line in sys.stdin:
    line = line.rstrip()[:-1]

    name, rule = line.split(' contain ')

    name = ' '.join(name.split()[:-1])
    if rule == 'no other bags':
        rules[name] = []
        continue

    contains = []
    for r in rule.split(', '):
        r = r.split()[:-1]
        cnt = int(r[0])
        rname = ' '.join(r[1:])
        contains.append((rname, cnt))
    rules[name] = contains

reverse = {name: set() for name in rules}
for name, contains in rules.items():
    for (n, _) in contains:
        reverse[n].add(name)

seen = set()
def dfs(name):
    for n in reverse[name]:
        if n in seen:
            pass
        seen.add(n)
        dfs(n)
    
dfs('shiny gold')
print(len(seen))
