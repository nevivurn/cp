#!/usr/bin/env python3

a, b = map(int, input().split('-'))

def check(s):
    d = False
    cnt = 0
    for (i, c) in enumerate(s[1:]):
        if c < s[i]:
            return False
        if c == s[i]:
            cnt += 1
        else:
            if cnt == 1:
                d = True
            cnt = 0
    return d or cnt == 1

cnt = 0
for i in range(a, b+1):
    print(i, check(str(i)))
    if check(str(i)):
        cnt += 1
print(cnt)
