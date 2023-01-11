#!/usr/bin/env python3
from math import factorial as fact
import sys
INF = 10 ** 20

def binom(n, k):
    return fact(n) // fact(k) // fact(n - k)

def get(n, k, com):
    ans = 0
    com = [0] + com
    for i in range(1, k + 1):
        for j in range(com[i - 1] + 1, com[i]):
            ans += binom(n - j, k - i)
    return ans

n, k = map(int, input().split())
com = list(map(int, input().split()))
print(get(n, k, com))
