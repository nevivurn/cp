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

nodep = list()
for node in nodes:
    for dep in deps:
        if dep[1] == node:
            break
    else:
        nodep.append(node)

topo = list()
while len(nodep) > 0:
    nodep = sorted(nodep)
    node = nodep.pop(0)

    topo.append(node)
    deps = [dep for dep in deps if dep[0] != node]
    for node in nodes:
        if node in topo or node in nodep:
            continue
        for dep in deps:
            if dep[1] == node:
                break
        else:
            nodep.append(node)

print(''.join(topo))
