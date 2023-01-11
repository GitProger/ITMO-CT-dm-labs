#!/usr/bin/env python3

a = list(map(int, input().split('+')))
s = sum(a)
dp = [[0 for i in range(s + 10)] for j in range(s + 10)] 
for i in range(s + 10):
	dp[i][i] = 1 

for i in range(1, s + 1):
    for j in range(i - 1, 0, -1):
        dp[i][j] = dp[i - j][j] + dp[i][j + 1] # count of partitions of i where all comonents not less than j

def get(a, pref=[], st=1, ans=0):
    got, sm = sum(pref), sum(a)
    if got == sm:
        if pref == a:
            return ans
        ans += 1
    for i in range(st, sm + 1):
        if got + i <= sm:
            if a[len(pref)] == i:
                return get(a, pref + [i], i, ans)
            ans += dp[sm - got - i][i]
 
print(get(a))