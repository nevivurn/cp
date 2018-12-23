#!/usr/bin/env python3

import sys
import re

deps = list()
nodes = set()

for line in sys.stdin:
    m = re.search('Step (.) must be finished before step (.) can begin.', line)
    deps.append((m.group(1), m.group(2)))
    nodes.add(m.group(1))
    nodes.add(m.group(2))

times = dict()

sec = 0
while len(times) < len(nodes):
    cnt = sum(1 for t in times.values() if t > sec)

    nodeps = []
    for node in nodes:
        if node in times:
            continue
        for dep in deps:
            if dep[1] == node and times.get(dep[0], sec+1) > sec:
                break
        else:
            nodeps.append(node)
    nodeps = sorted(nodeps)

    while cnt < 15 and len(nodeps) > 0:
        node = nodeps.pop(0)
        times[node] = sec+60+ ord(node)-ord('A')+1

    sec = min(t for t in times.values() if t > sec)

print(max(times.values()))
