#!/usr/bin/env python3
from math import *
from fractions import Fraction
def neat(a: "List of fractions"):
    return "[" + ", ".join(map(lambda f: str(f), a)) + "]"
DEBUG = 0

alpha = list(map(chr, range(ord('a'), ord('a') + int(input()))))

f = list(map(int, input().split()))
n = sum(f)

code = input()
t = Fraction(int(code, 2), 2 ** len(code))
ans = ""

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


if DEBUG: print(neat(ps))

for i in range(n):
    index = -1
    for j in range(0, len(ps) - 1):
        if ps[j] < t < ps[j + 1]:
           index = j
           break

    ans += alpha[index]
    ps = zoom(ps, index, p) #zoom
    if DEBUG: print(neat(ps))

print(ans)

'''
3                                  
abacaba
4 2 1
011
'''
