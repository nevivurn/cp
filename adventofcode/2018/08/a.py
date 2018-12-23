#!/usr/bin/env python3

nums = map(int, input().split())

def metasum(nums):
    cs, ms = next(nums), next(nums)

    n = sum(metasum(nums) for i in range(cs))
    n += sum(next(nums) for i in range(ms))
    return n

print(metasum(nums))
