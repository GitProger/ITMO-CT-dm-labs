#!/usr/bin/env python3
# https://neerc.ifmo.ru/wiki/index.php?title=%D0%98%D0%B7%D0%B1%D1%8B%D1%82%D0%BE%D1%87%D0%BD%D0%BE%D0%B5_%D0%BA%D0%BE%D0%B4%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5,_%D0%BA%D0%BE%D0%B4_%D0%A5%D1%8D%D0%BC%D0%BC%D0%B8%D0%BD%D0%B3%D0%B0#:~:text=%D0%98%D0%B7%D0%B1%D1%8B%D1%82%D0%BE%D1%87%D0%BD%D0%BE%D0%B5%20%D0%BA%D0%BE%D0%B4%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5%20(%D0%B0%D0%BD%D0%B3%D0%BB.,%D0%B5%D1%91%20%D0%BF%D0%B5%D1%80%D0%B5%D0%B4%D0%B0%D1%87%D0%B5%20%D0%BF%D0%BE%20%D0%BB%D0%B8%D0%BD%D0%B8%D1%8F%D0%BC%20%D1%81%D0%B2%D1%8F%D0%B7%D0%B8.
from math import *

def to_str(a):
    return ''.join(map(str, a))

def ctrl(a):
    x = 0
    for e in a: 
        x ^= e
    return x

def getpos(s, k, bit):
    return list(filter(lambda i: (i >> k) & 1 == bit, range(len(s))))

def sm(s, k, bit):
    return sum(map(lambda x: s[x], getpos(s, k, bit))) % 2

def getcode(s):
    c = []
    for k in range(ceil(log2(len(s)))):
    	c += [sm(s, k, 0), sm(s, k, 1)]
    return c + [ctrl(c)]

t = int(input())
s = list(map(int, input()))

#k = 1
#while k < len(s): k *= 2
#while len(s) < k: s.append(0)


if t == 1:
    print(to_str(s) + to_str(getcode(s)))
    exit(0)

#t == 2

n = 0
for k in range(len(s)): # 2 ^ k + 2k = n
    n = len(s) - 2 * k - 1
    if ceil(log2(n)) == k:
        break

x, y = s[:n], s[n:]
if y[:-1] == getcode(x)[:-1]: #no error or error in ctrl bit
    print(to_str(x))
    exit(0)

if ctrl(y[:-1]) != y[-1]: #error in code
    print(to_str(x))
    exit(0)


pos = set(range(n))
for k in range(len(y) // 2):
    s0 = y[2 * k]
    s1 = y[2 * k + 1]
#    print(pos)

    if s0 != sm(x, k, 0):
        pos = pos & set(getpos(x, k, 0))
    elif s1 != sm(x, k, 1):
        pos = pos & set(getpos(x, k, 1))
    
if len(pos) != 1:
    print("Count of errors > 1: ", len(pos))
    exit(-1)
else:
    p = min(pos)
    x[p] = 1 - x[p]
    print(to_str(x))
