#!/usr/bin/env python3
import sys
sys.setrecursionlimit(100000)
def memo(f):
    tab = {}
    def f_mod(*x): # x, x <--> tuple([*x]), *x
        if tab.get(tuple([*x])) == None:
            tab[tuple([*x])] = f(*x)
        return tab[tuple([*x])]
    return f_mod

def fib(n):
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)

fib = memo(fib)

print(fib(1000))
