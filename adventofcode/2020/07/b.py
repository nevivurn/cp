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

ans = {name: None for name in rules}
def dfs(name):
    if ans[name]:
        return ans[name]

    cnt = 1
    for (n, c) in rules[name]:
        cnt += c*dfs(n)

    ans[name] = cnt
    return cnt
    
dfs('shiny gold')
print(ans['shiny gold'] - 1)
