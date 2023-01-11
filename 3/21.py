#!/usr/bin/env python3

n, r = list(map(int, input().split()))
dp = [[0 for i in range(n + 10)] for j in range(n + 10)] 
for i in range(n + 10):
    dp[i][i] = 1 

for i in range(1, n + 1):
    for j in range(i - 1, 0, -1):
        dp[i][j] = dp[i - j][j] + dp[i][j + 1] # count of partitions of i where all comonents not less than j


def get(r, p=[]):
    sm = sum(p)
    for c in range(p[-1] if len(p) > 0 else 1, n + 1):
        if sm + c <= n:
            t = dp[n - sm - c][c]
            if t <= r:
                r -= t
            else:
                return get(r, p + [c]);
    if r == 0:
        return ('+'.join(map(str, p + [n - sm])))

print(get(r))