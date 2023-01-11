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

def gen(dp, n, k, p='', balance=[], brace_stack=[]):
    # ( < ) < [ < ]
    op, cl = "([", ")]" # can be extended  op, cl = "([{<", ")]}>"
    if balance == []:
    	balance = [0] * len(op)

    if len(p) == 2 * n:
        if k == 0:
            return p
        print("Error")

    s_bal = sum(balance)

    cnt_if_op = dp[2 * n - len(p) - 1][s_bal + 1] * 2 ** ((2 * n - len(p) - s_bal) // 2 - 1)
    cnt_if_cl = dp[2 * n - len(p) - 1][s_bal - 1] * 2 ** ((2 * n - len(p) - s_bal) // 2)

    if all(map(lambda b: b <= 0, balance)):
    	cnt_if_cl = 0

    for i in range(len(op)):
        if s_bal + 1 < 2 * n - len(p):
            if k < cnt_if_op:
                brace_stack.append(op[i])
                balance[i] += 1
                return gen(dp, n, k, p + op[i], balance, brace_stack)
            k -= cnt_if_op

        if balance[i] > 0 and brace_stack[-1] == op[i]:
            if k < cnt_if_cl:
                brace_stack.pop()
                balance[i] -= 1
                return gen(dp, n, k, p + cl[i], balance, brace_stack)
            k -= cnt_if_cl

n, k = map(int, input().split())
print(gen(get_dp(200), n, k))

'''
([])()[]
'''