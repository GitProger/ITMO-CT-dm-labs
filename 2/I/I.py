#!/usr/bin/env python3
# https://www.youtube.com/watch?v=MQUg1xtLtp4
from math import *
import sys
t = int(input())
s = list(map(int, input()))

def to_str(a):
    return ''.join(map(str, a))

def isp2(n):
    return (n & (n - 1) == 0) and n != 0

def sm(s, k):
    return sum([s[x] for x in filter(
        lambda i: ((i + 1) >> k) & 1 == 1 and not isp2(i + 1),
        range(len(s)))]) % 2

if t == 1:
    code = []
    i = 1
    j = 0
    while j < len(s):
        if not isp2(i):
            code.append(s[j])
            j += 1
        else:
            code.append(0)
        i += 1
    
    for j in range(ceil(log2(len(code)))):
        code[2 ** j - 1] = sm(code, j)
    print(to_str(code))
else:
    pos = list(filter(lambda i: not isp2(i + 1), range(len(s))))
    bad = False
    p = -1
    for j in range(ceil(log2(len(pos)))):
        if s[2 ** j - 1] != sm(s, j):
            bad = True
            p += 2 ** j # bit j is set
    if bad:
        s[p] ^= 1
    print(to_str([s[i] for i in pos]))
