#!/usr/bin/env python3

def index(a, f):
    for i in range(len(a)):
        if f(a[i]):
            return i
    return -1

n, k = map(int, input().split())
a = [list(map(int, input().split())) for i in range(k)]


good = [n - a[i].count(-1) for i in range(k)]
used = [0 for i in range(k)]
occ = [-1 for i in range(n)]

while True: 
    cond = 0
    for i in range(k):
        if good[i] == 1 and not used[i]:
            used[i] = 1
            cond = 1
            ok = index(a[i], lambda x: x != -1)
            occ[ok] = a[i][ok]

            for j in range(k):
                if used[j]: continue
                if a[j][ok] == -1: continue
                if a[j][ok] == occ[ok]:
                    used[j] = 1
                else:
                    a[j][ok] = -1
                    good[j] -= 1
                    if good[j] == 0:
                        print("YES")
                        exit(0)
    if not cond: break

print("NO")