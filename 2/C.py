#!/usr/bin/env python3

def rev(bwt, index):
    n = len(bwt)
    a = ['' for _ in range(n)]
    for i in range(n):
        a = list(map(lambda j: bwt[j] + a[j], range(n)))
        a.sort()
    return a[index]



print(rev(input(), 0))