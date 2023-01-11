#!/usr/bin/env python3
# https://neerc.ifmo.ru/wiki/index.php?title=%D0%A7%D0%B8%D1%81%D0%BB%D0%B0_%D0%A1%D1%82%D0%B8%D1%80%D0%BB%D0%B8%D0%BD%D0%B3%D0%B0_%D0%B2%D1%82%D0%BE%D1%80%D0%BE%D0%B3%D0%BE_%D1%80%D0%BE%D0%B4%D0%B0
from copy import deepcopy

def gen(n, k):
    if n < k:
        return []
    if k == 1:
        return [[list(range(1, n + 1))]]
    ans = []

    for partition in gen(n - 1, k - 1):
        partition.append([n])
        ans.append(partition)

    for partition in gen(n - 1, k):
        for bunch in partition:
            bunch.append(n)
            ans.append(deepcopy(partition))
            bunch.pop()

#    for partition in gen(n - 1, k):
#        for i in range(len(partiton)):
#            partition[i].append(n)
#            ans.append(deepcopy(partition))
#            partition[i].pop()

    return ans

n, k = map(int, input().split())
ans = gen(n, k)
for partition in ans:
    for set_ in partition:
        print(*set_)
    print()

