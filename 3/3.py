#!/usr/bin/env python3

def t3(x, ln):
    ans = ''
    for i in range(ln):
        ans = str(x % 3) + ans
        x //= 3
    return ans

def shift(s):
    return s.translate({
        ord('0'): ord('1'),
        ord('1'): ord('2'),
        ord('2'): ord('0')
    })

n = int(input())
for i in range(3 ** (n - 1)):
    s = t3(i, n)
    print(s)
    print(shift(s))
    print(shift(shift(s)))

'''
 0
 1
 2
  

 00 -
 01
 02
 12
 11 -
 10
 20
 21
 22 -
 '''