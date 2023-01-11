#!/usr/bin/env python3

def gen(n, p=[]):
    if len(p) == n:
        s = ''.join(p)
        bal = 0
        ok = True
        for i in range(len(s)):
            if s[i] == "(":
                bal += 1
            else:
                bal -= 1
            if bal < 0:
                ok = False
                break
        if ok and bal == 0:
            print(s)
        return
    for i in ['(', ')']:
        gen(n, p + [i])

n = int(input())
gen(2 * n)