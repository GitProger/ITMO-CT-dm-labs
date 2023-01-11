#!/usr/bin/env python3
# https://e-maxx.ru/algo/bracket_sequences
from copy import deepcopy
from math import factorial as fact
import sys
INF = 10 ** 20

def get_dp(n):
    dp = [[0 for j in range(n + 1)] for i in range(2 * n + 1)]
    dp[0][0] = 1
    for i in range(1, 2 * n + 1):
        for j in range(n + 1):
            if j > 0:
                dp[i][j] += dp[i - 1][j - 1]
            if j + 1 <= n:
                dp[i][j] += dp[i - 1][j + 1]
    return dp

def gen(n, k, p='', ro_balance=0, sq_balance=0, brace_stack=[]):
    if len(p) == 2 * n:
        if k == 0:
            return p
        print("Error")

    cnt_if_op = dp[2 * n - len(p) - 1][ro_balance + sq_balance + 1] * 2 ** ((2 * n - len(p) - sq_balance - ro_balance) // 2 - 1)
    cnt_if_cl = dp[2 * n - len(p) - 1][ro_balance + sq_balance - 1] * 2 ** ((2 * n - len(p) - sq_balance - ro_balance) // 2) if ro_balance > 0 or sq_balance > 0 else 0

    if sq_balance + ro_balance + 1 < 2 * n - len(p):
        if k < cnt_if_op:
            brace_stack.append('(')
            return gen(n, k, p + '(', ro_balance + 1, sq_balance, brace_stack)
        k -= cnt_if_op


    if ro_balance > 0 and brace_stack[-1] == '(':
        if k < cnt_if_cl:
            brace_stack.pop()
            return gen(n, k, p + ')', ro_balance - 1, sq_balance, brace_stack)
        k -= cnt_if_cl

    if sq_balance + ro_balance + 1 < 2 * n - len(p):
        if k < cnt_if_op:
            brace_stack.append('[')
            return gen(n, k, p + '[', ro_balance, sq_balance + 1, brace_stack)
        k -= cnt_if_op

    if sq_balance > 0 and brace_stack[-1] == '[':
        if k < cnt_if_cl:
            brace_stack.pop()
            return gen(n, k, p + ']', ro_balance, sq_balance - 1, brace_stack)
        k -= cnt_if_cl


n, k = map(int, input().split())
dp = get_dp(n)
print(gen(n, k))

'''
([])()[]
'''