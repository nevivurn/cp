#!/usr/bin/env python3

nums = list(map(int, input().split(',')))
nums[1] = 12
nums[2] = 2
ind = 0
while True:
    op = nums[ind]
    if op == 99:
        break
    if op == 1:
        a = nums[nums[ind+1]]
        b = nums[nums[ind+2]]
        nums[nums[ind+3]] = a+b
    elif op == 2:
        a = nums[nums[ind+1]]
        b = nums[nums[ind+2]]
        nums[nums[ind+3]] = a*b
    else:
        print('err')
        break
    ind += 4
print(nums[0])
