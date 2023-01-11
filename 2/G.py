#!/usr/bin/env python3
from math import *
from fractions import Fraction
def neat(a: "List of fractions"):
    return "[" + ", ".join(map(lambda f: str(f), a)) + "]"
DEBUG = 0


sz = int(input())
alpha = list(map(chr, range(ord('a'), ord('a') + sz)))
s = input()
n = len(s)

f = []
p = []
for c in alpha:
    f.append(s.count(c))
    p.append(Fraction(s.count(c), n))
print(sz)
print(*f)
###############################################

p = [0] + list(map(lambda x: Fraction(x, n), f))
ps = p[::]
for i in range(1, len(ps)):
    ps[i] += ps[i - 1]

def zoom(ps, i, p):
    l = ps[i]
    r = ps[i + 1]
    ps = list(map(lambda x: x * (r - l), p))
    for i in range(1, len(ps)):
        ps[i] += ps[i - 1]
    return list(map(lambda x: x + l, ps))

for c in s:
    ps = zoom(ps, alpha.index(c), p)


l, r = ps[0], ps[-1]
for q in range(1, 1000):
    u = ceil(l * 2 ** q)
    if u < r * 2 ** q:
        print(bin(int(u))[2:].zfill(q))
        break
