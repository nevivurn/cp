#!/usr/bin/env python3

a, b = map(int, input().split('-'))

def check(s):
    d = False
    for (i, c) in enumerate(s[1:]):
        if c == s[i]:
            d = True
        if c < s[i]:
            return False
    return d

cnt = 0
for i in range(a, b+1):
    print(i, check(str(i)))
    if check(str(i)):
        cnt += 1
print(cnt)
