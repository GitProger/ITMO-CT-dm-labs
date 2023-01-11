#!/usr/bin/env python3
from math import factorial as fact
from sys import stderr
INF = 10 ** 20

def binom(n, k):
    if n - k < 0:
        return 0
    return fact(n) // fact(k) // fact(n - k)

def get(s):
    N = 100
    dp = [[0 for _ in range(2 * N)] for __ in range(2 * N)]
    dp[0][0] = 1 # dp[i][j] - cnt of seq of length i and balance j
    for i in range(1, N):
        for j in range(N):
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]

    n = len(s) // 2
    ans = 0
    depth = 0
    for i in range(2 * n):
        if s[i] == '(':
            depth += 1
        else:
            ans += dp[2 * n - i - 1][depth + 1]
            depth -= 1
    return ans

s = input()
print(get(s))


'''
(((()))) 0
((()())) 1 
((())()) 2
((()))() 3
(()(())) 4
(()()()) 5
(()())() 6 
(())(()) 7
(())()() 8
()((())) 9 
()(()()) 10
()(())() 11
()()(()) 12
()()()() 13
'''