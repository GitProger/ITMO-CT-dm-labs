#!/usr/bin/env python3
from math import factorial as fact
import sys
INF = 10 ** 20

def binom(n, k):
    if n - k < 0:
        return 0
    return fact(n) // fact(k) // fact(n - k)

def gen(k, m, src, p=[]):
    '''
       k - length of seq
       m - number of required seq
       src - pull of acceptable number in least suffix
       p - current built prefix
    '''
    if len(p) == k:
        if m == 0:
            print(*p)
        return
    for i in range(len(src)):
        def less(ind):
            return binom(len(list(filter(lambda x: x > (src[ind] if ind < len(src) else INF), src))), k - 1 - len(p))
        def less_total(ind):
            res = 0
            for j in range(0, ind):
                res += less(j)
            return res

        m1 = m - less_total(i)
        m2 = m - less_total(i + 1)
        if m1 >= 0 and m2 < 0:
            return gen(k, m1, list(filter(lambda x: x > src[i], src)), p + [src[i]])


n, k, m = map(int, input().split())
gen(k, m, list(range(1, n + 1)))

'''
1 2   0
1 3   1
1 4   2
2 3   3
2 4   4
3 4   5
'''
