#!/usr/bin/env python3
# https://e-maxx.ru/algo/bracket_sequences
from copy import deepcopy
from math import factorial as fact
import sys
INF = 10 ** 20

def get(s):
    n = len(s) // 2
    ans = 0
    dp = [[0 for j in range(n + 1)] for i in range(2 * n + 1)]
    dp[0][0] = 1
    for i in range(1, 2 * n + 1):
        for j in range(n + 1):
            if j > 0:
                dp[i][j] += dp[i - 1][j - 1]
            if j + 1 <= n:
                dp[i][j] += dp[i - 1][j + 1]

    depth = 0
    a = []
    for i in range(2 * n):
        r = 2 * n - i - 1
        if (s[i] == '('):
            a.append('(')
            depth += 1
        else:
            if depth < n: 
                ans += dp[r][depth + 1] * int(2 ** ((r - (depth + 1)) // 2))
            if (s[i] == ')'):
                depth -= 1
                a.pop()
            else:
                if len(a) != 0 and a[-1] == '(':
                    ans += dp[r][depth - 1] * int(2 ** ((r - (depth - 1)) // 2))
                if s[i] == '[':
                    a.append('[')
                    depth += 1
                else:
                    if depth < n:
                        ans += dp[r][depth + 1] * int(2 ** ((r - (depth + 1)) // 2))
                    a.pop()
                    depth -= 1
    return ans


s = input()
print(get(s))

'''
([])()[]
'''