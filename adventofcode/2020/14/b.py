#!/usr/bin/env python3

import sys

d = dict()

def numeric_masks(smask):
    tmask = int(smask.replace('X', '0'), base=2)
    fmask = int(smask.replace('X', '1'), base=2)
    return (tmask, fmask)

def expand_masks(mask):
    if '.' not in mask:
        return [mask]
    i = mask.index('.')
    return expand_masks(mask[:i] + '0' + mask[i+1:]) + expand_masks(mask[:i] + '1' + mask[i+1:])

masks = []
for line in sys.stdin:
    lhs, _, rhs = line.rstrip().split()
    if lhs == 'mask':
        rhs = rhs.replace('X', '.').replace('0', 'X')
        masks = expand_masks(rhs)
    else:
        addr = int(lhs[4:-1])
        num = int(rhs)
        for mask in masks:
            tmask, fmask = numeric_masks(mask)
            d[addr & fmask | tmask] = num

print(sum(d.values()))
