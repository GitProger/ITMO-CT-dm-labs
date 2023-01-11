#!/usr/bin/env python3
from math import factorial as fact
import sys
INF = 10 ** 20
# https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D0%BE%D0%BB%D1%83%D1%87%D0%B5%D0%BD%D0%B8%D0%B5_%D1%81%D0%BB%D0%B5%D0%B4%D1%83%D1%8E%D1%89%D0%B5%D0%B3%D0%BE_%D0%BE%D0%B1%D1%8A%D0%B5%D0%BA%D1%82%D0%B0#.D0.A1.D0.BF.D0.B5.D1.86.D0.B8.D0.B0.D0.BB.D0.B8.D0.B7.D0.B0.D1.86.D0.B8.D1.8F_.D0.B0.D0.BB.D0.B3.D0.BE.D1.80.D0.B8.D1.82.D0.BC.D0.B0_.D0.B4.D0.BB.D1.8F_.D0.B3.D0.B5.D0.BD.D0.B5.D1.80.D0.B0.D1.86.D0.B8.D0.B8_.D1.81.D0.BB.D0.B5.D0.B4.D1.83.D1.8E.D1.89.D0.B5.D0.B3.D0.BE_.D1.81.D0.BE.D1.87.D0.B5.D1.82.D0.B0.D0.BD.D0.B8.D1.8F

def next_comb(a, n, k):
    b = a + [n + 1]
    i = k - 1
    while i >= 0 and b[i] + 1 >= b[i + 1]:
        i -= 1
    if i < 0:
    	return [-1]
    b[i] += 1
    for j in range(i + 1, k):
        b[j] = b[j - 1] + 1
    return b[:-1]

n, k = map(int, input().split())
a = list(map(int, input().split()))
print(' '.join(map(str, next_comb(a, n, k))))