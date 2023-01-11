#!/usr/bin/env python3
import math
from functools import reduce

def rev(c):
    if c == '0':
        return '1'
    else:
        return '0'

def t0_cl(f):
    return int(f[0] == '0')

def t1_cl(f):
    return int(f[-1] == '1')

def s_cl(f):
    if len(f) == 1:
        return 0
    s = int(math.log2(len(f)))
    ans = 1
    for i in range(len(f)): #2 ** s
        b_rev = ''.join(map(rev, list(bin(i)[2:].zfill(s))))
        i_rev = int(b_rev, 2)
        if f[i_rev] != rev(f[i]):
            ans = 0
    return ans
    
def m_cl(f):
    if len(f) == 1:
        return 1
    s = int(math.log2(len(f)))
    ans = 1
    for i in range(len(f)):
        if ans == 0:
            return ans
        for j in range(len(f)):
            mon = True
            b_i = bin(i)[2:].zfill(s)
            b_j = bin(j)[2:].zfill(s)
            for idx in range(s):
                if int(b_i[idx]) > int(b_j[idx]):
                    mon = False
                    break
            if mon and int(f[i]) > int(f[j]):
                ans = 0
    return ans
    
def l_cl(f):
    if len(f) == 1:
        return 1
    s = int(math.log2(len(f)))
    for a_map in range(2 * len(f)): # jegalkin koefs
        ans = 1
        b_a_map = bin(a_map)[2:].zfill(s + 1)
        for arg in range(len(f)):
            b_arg = bin(arg)[2:].zfill(s)
            jeg = [int(b_a_map[-1])] + [int(b_arg[i]) * int(b_a_map[i]) for i in range(s)]
            if reduce(lambda a, b: a ^ b, jeg) != int(f[arg]):
                ans = 0
                break
        if ans == 1:
            return 1
    return 0
    
funcs = []
for i in range(int(input())):
    ln, f = input().split()
    funcs.append(f)


if all(map(t0_cl, funcs)) or all(map(t1_cl, funcs)) or all(map(s_cl, funcs)) or all(map(m_cl, funcs)) or all(map(l_cl, funcs)):
    print("NO")
else:
    print("YES")
