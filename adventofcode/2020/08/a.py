#!/usr/bin/env python3

import sys

ops = []
for line in sys.stdin:
    op, arg = line.rstrip().split()
    ops.append((op, int(arg)))

seen = set()
pc = 0
acc = 0
while True:
    if pc in seen:
        break
    seen.add(pc)

    op, arg = ops[pc]
    if op == 'acc':
        pc += 1
        acc += arg
    elif op == 'nop':
        pc += 1
    elif op == 'jmp':
        pc += arg

print(acc)
