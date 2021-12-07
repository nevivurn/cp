#!/usr/bin/env python3

l = list(sorted(map(int, input().split(','))))

cur = l[len(l)//2]
print(sum(map(lambda x: abs(x-cur), l)))
