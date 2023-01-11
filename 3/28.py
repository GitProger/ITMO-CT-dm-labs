#!/usr/bin/env python3
from math import factorial as fact
import sys
INF = 10 ** 20
# https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D0%BE%D0%BB%D1%83%D1%87%D0%B5%D0%BD%D0%B8%D0%B5_%D1%81%D0%BB%D0%B5%D0%B4%D1%83%D1%8E%D1%89%D0%B5%D0%B3%D0%BE_%D0%BE%D0%B1%D1%8A%D0%B5%D0%BA%D1%82%D0%B0#.D0.A1.D0.BF.D0.B5.D1.86.D0.B8.D0.B0.D0.BB.D0.B8.D0.B7.D0.B0.D1.86.D0.B8.D1.8F_.D0.B0.D0.BB.D0.B3.D0.BE.D1.80.D0.B8.D1.82.D0.BC.D0.B0_.D0.B4.D0.BB.D1.8F_.D0.B3.D0.B5.D0.BD.D0.B5.D1.80.D0.B0.D1.86.D0.B8.D0.B8_.D1.81.D0.BB.D0.B5.D0.B4.D1.83.D1.8E.D1.89.D0.B5.D0.B9_.D0.BC.D1.83.D0.BB.D1.8C.D1.82.D0.B8.D0.BF.D0.B5.D1.80.D0.B5.D1.81.D1.82.D0.B0.D0.BD.D0.BE.D0.B2.D0.BA.D0.B8

def next_multi(n, a):
    i = n - 2
    while i >= 0 and a[i] >= a[i + 1]: 
        i -= 1
    if i >= 0:
        j = i + 1
        while j < n - 1 and a[j + 1] > a[i]:
            j += 1
        a[i], a[j] = a[j], a[i]
        a[i + 1:n] = a[i + 1:n][::-1]
        return a
    else:
        return [0] * n

n = int(input())
a = list(map(int, input().split()))

print(' '.join(map(str, next_multi(n, a))))