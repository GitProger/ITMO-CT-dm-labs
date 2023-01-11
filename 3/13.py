#!/usr/bin/env python3
from math import *
fact = factorial

def gen(n, k, src, p=[]):
    if len(p) == n and k == 0:
        return print(*p)
    for i in range(len(src)):
        if len(src) == 0:
            return
        k1 = k - (i - 0) * fact(len(src) - 1)
        k2 = k - (i + 1) * fact(len(src) - 1)
        if k1 >= 0 and k2 < 0:
            p.append(src[i])
            src.remove(src[i])
            gen(n, k1, src, p)
            break

n, k = map(int, input().split())
gen(n, k, list(range(1, n + 1)))

'''

'''
