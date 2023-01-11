#!/usr/bin/env python3
 
def gen(n, p=[]):
    if len(p) > n:
        return
    print(*p)
    for i in range(p[-1] if len(p) > 0 else 1, n + 1):
        if i not in p:
            gen(n, p + [i])
 
n = int(input())
gen(n)