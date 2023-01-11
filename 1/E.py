#!/usr/bin/env python3
import math, random
from functools import reduce

def binary_subset(x: int):
    ans = []
    for i in range(x):
        if i & x == i:
            ans.append(i)
    return ans


def zhegalkin(n, a):
    koef = [-1 for i in range(2 ** n)]
    koef[0] = a[0]
#   koef[x] = a[x] xor (koef[i], i in subset(x))
    def calc(x):
        if koef[x] != -1:
            return koef[x]
        koef[x] = a[x]
        for i in binary_subset(x):
            koef[x] ^= calc(i)
        return koef[x]

    calc(2 ** n - 1)
    return koef

n = int(input())
a = []
for i in range(2 ** n):
    s, r = input().split()
    #r = random.randint(0, 1)
    r = int(r)
    a.append(r)

zh = zhegalkin(n, a)
for i in range(2 ** n):
    print(bin(i)[2:].zfill(n), zh[i])

'''
2
00 0
01 1
10 0
11 1

2
00 1
01 0
10 0
11 1


'''