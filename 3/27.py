#!/usr/bin/env python3
from math import factorial as fact
import sys
INF = 10 ** 20
# https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D1%80%D0%B0%D0%B2%D0%B8%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5_%D1%81%D0%BA%D0%BE%D0%B1%D0%BE%D1%87%D0%BD%D1%8B%D0%B5_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8#.D0.9F.D0.BE.D0.BB.D1.83.D1.87.D0.B5.D0.BD.D0.B8.D0.B5_k-.D0.B9_.D0.BF.D0.BE.D1.81.D0.BB.D0.B5.D0.B4.D0.BE.D0.B2.D0.B0.D1.82.D0.B5.D0.BB.D1.8C.D0.BD.D0.BE.D1.81.D1.82.D0.B8

def next_seq(s):
    co, cc = 0, 0
    for i in range(len(s) - 1, -1, -1):
        if s[i] == '(':
            co += 1
            if co < cc: break
        else:
            cc += 1
    # ()).. -> )()..      # .. - correct brace seq
    s = s[:len(s) - co - cc]
    if s == "":
        return "-"
    else:
        return s + ')' + '(' * co + ')' * (cc - 1)

print(next_seq(input()))