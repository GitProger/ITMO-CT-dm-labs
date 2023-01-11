#!/usr/bin/env python3
# https://e-maxx.ru/algo/bracket_sequences
from copy import deepcopy
from math import factorial as fact
import sys
INF = 10 ** 20

def solve(n, a):
    used = []
    last = False
    for i in reversed(range(len(a))):
        if last: break

        if len(used) != 0 and max(used) > a[i][-1]:
            m = min(filter(lambda e: e > a[i][-1], used))
            used.remove(m)
            a[i].append(m)
            break

        for j in reversed(range(len(a[i]))):
            if len(used) != 0 and j > 0 and max(used) > a[i][j]:
                m = min(filter(lambda e: e > a[i][j], used))
                used.remove(m)
                used.append(a[i][j])
                a[i][j] = m
                last = True
                break
            else:
                used.append(a[i][-1])
                a[i].pop()
                if len(a[i]) == 0:
                    a.pop()
   
    a += [[i] for i in sorted(used)]

    print(n, len(a))
    for distibution in a:
        print(*distibution)
    print()


def read_a():
    return list(map(int, input().split()))

while True:
    n, k = read_a()
    if n == 0 and k == 0:
        break
    a = [read_a() for i in range(k)]
    input()
    solve(n, a)
