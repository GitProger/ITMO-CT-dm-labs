#!/usr/bin/env python3

def gen(n, p=[]):
    if n == 0:
        print('+'.join(map(str, p)))
    for i in range(p[-1] if len(p) > 0 else 1, n + 1):
        gen(n - i, p + [i])

n = int(input())
gen(n)