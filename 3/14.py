#!/usr/bin/env python3
from math import factorial as f

n = int(input())
p = list(map(int, input().split()))
print(sum(sum(map(lambda x: x < p[i], p[i:])) * f(len(p) - i - 1) for i in range(n)))

#ans = 0
#for i in range(n):
#    ans += sum(map(lambda x: x < p[0], p)) * f(len(p) - 1)
#    p = p[1:]
