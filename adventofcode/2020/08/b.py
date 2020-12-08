#!/usr/bin/env python3

import sys

ops = []
for line in sys.stdin:
    op, arg = line.rstrip().split()
    ops.append((op, int(arg)))

def run(ops):
    seen = set()
    pc = 0
    acc = 0
    while True:
        if pc == len(ops):
            return acc

        if pc in seen or not 0 <= pc < len(ops):
            return None
        seen.add(pc)

        op, arg = ops[pc]
        if op == 'acc':
            pc += 1
            acc += arg
        elif op == 'nop':
            pc += 1
        elif op == 'jmp':
            pc += arg

for i, (op, arg) in enumerate(ops):
    if op == 'nop':
        ops[i] = ('jmp', arg)
    elif op == 'jmp':
        ops[i] = ('nop', arg)
    else:
        continue

    ans = run(ops)
    if ans is not None:
        print(ans)
        break

    ops[i] = (op, arg)
