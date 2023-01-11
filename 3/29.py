#!/usr/bin/env python3
from math import factorial as fact
import sys
INF = 10 ** 20

def get_next(a):
    a[-2] += 1
    a[-1] -= 1
    if a[-2] <= a[-1]:
        while 2 * a[-2] <= a[-1]:
            a.append(a[-1] - a[-2])
            a[-2] = a[-3]
    else:
        a[-2] += a[-1]
        a.pop()
    return a

# 5=1+1+3
s, rest = input().split('=')
a = list(map(int, rest.split('+')))

if len(a) == 1:
	print("No solution")
else:
	print(s + '=' + '+'.join(map(str, get_next(a))))