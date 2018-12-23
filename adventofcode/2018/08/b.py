#!/usr/bin/env python3

nums = map(int, input().split())

def parse(nums):
    cs, ms = next(nums), next(nums)

    children = [parse(nums) for i in range(cs)]
    meta = [next(nums) for i in range(ms)]
    return (children, meta)


def value(node):
    if len(node[0]) == 0:
        return sum(node[1])

    val = 0
    for meta in node[1]:
        if meta != 0 and meta <= len(node[0]):
            val += value(node[0][meta-1])
    return val

print(value(parse(nums)))
