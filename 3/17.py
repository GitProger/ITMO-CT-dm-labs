#!/usr/bin/env python3
from math import factorial as fact
from sys import stderr
INF = 10 ** 20

# https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D1%80%D0%B0%D0%B2%D0%B8%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5_%D1%81%D0%BA%D0%BE%D0%B1%D0%BE%D1%87%D0%BD%D1%8B%D0%B5_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8#.D0.9F.D0.BE.D0.BB.D1.83.D1.87.D0.B5.D0.BD.D0.B8.D0.B5_k-.D0.B9_.D0.BF.D0.BE.D1.81.D0.BB.D0.B5.D0.B4.D0.BE.D0.B2.D0.B0.D1.82.D0.B5.D0.BB.D1.8C.D0.BD.D0.BE.D1.81.D1.82.D0.B8

def binom(n, k):
    if n - k < 0:
        return 0
    return fact(n) // fact(k) // fact(n - k)

def get(n, k):
    depth = 0
    s = ""

    N = 100
    dp = [[0 for _ in range(2 * N)] for __ in range(2 * N)]
    dp[0][0] = 1 # dp[i][j] - cnt of seq of length i and balance j
    for i in range(1, N):
        for j in range(N):
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]

    for i in range(2 * n):
        if dp[2 * n - (i + 1)][depth + 1] >= k:
            s += '('
            depth += 1
        else:
            k -= dp[2 * n - (i + 1)][depth + 1]
            s += ')'
            depth -= 1
    return s

n, k = map(int, input().split())
print(get(n, k + 1))


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