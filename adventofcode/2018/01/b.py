#!/usr/bin/env python3

import sys
from itertools import cycle

d = cycle(int(line) for line in sys.stdin)

i = 0
s = set()
while i not in s:
    s.add(i)
    i += next(d)
print(i)
