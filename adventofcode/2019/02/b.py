#!/usr/bin/env python3

want = 19690720

orig = list(map(int, input().split(',')))

def evaluate(nums, a, b):
    nums[1] = a
    nums[2] = b
    ind = 0
    while True:
        op = nums[ind]
        if op == 99:
            return nums[0]
        if op == 1:
            a = nums[nums[ind+1]]
            b = nums[nums[ind+2]]
            nums[nums[ind+3]] = a+b
        elif op == 2:
            a = nums[nums[ind+1]]
            b = nums[nums[ind+2]]
            nums[nums[ind+3]] = a*b
        else:
            return -1
        ind += 4

for a in range(100):
    for b in range(100):
        if evaluate(orig.copy(), a, b) == want:
            print(a*100 + b)
