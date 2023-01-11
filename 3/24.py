#!/usr/bin/env python3


def prev_permutation(n, p):
    a = p[:]
    for i in reversed(range(n - 1)):
        if a[i] > a[i + 1]:
            break
    else:
        return [0] * n

    j = next(j for j in reversed(range(i + 1, n)) if a[i] > a[j])
    a[i], a[j] = a[j], a[i]
    a[i + 1:] = reversed(a[i + 1:])
    return a

def next_permutation(n, p):
    a = p[:]
    for i in reversed(range(n - 1)):
        if a[i] < a[i + 1]:
            break
    else:
        return [0] * n

    j = next(j for j in reversed(range(i + 1, n)) if a[i] < a[j])
    a[i], a[j] = a[j], a[i]
    a[i + 1:] = reversed(a[i + 1:])
    return a
    

n = int(input())
p = list(map(int, input().split()))
print(*prev_permutation(n, p))
print(*next_permutation(n, p))

