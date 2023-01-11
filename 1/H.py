#!/usr/bin/env python3
import sys
TEST = 0

if TEST:
    n = int(sys.argv[1])
    X = list(map(int, list(sys.argv[2])))[::-1]
    Y = list(map(int, list(sys.argv[3])))[::-1]

    def sh(a, b):
        return int(not (a and b))
    def nt(a):
        return sh(a, a)

    def A(a):
        return X[a]
    def B(b):
        return Y[b]

    def get(n):
        if n == 1:
            return sh(  sh(A(0), B(0)), sh(A(0), B(0))  )
        return sh(sh(get(n - 1), sh(nt(A(n - 1)), nt(B(n - 1)))), sh(A(n - 1), B(n - 1)))

    print(get(n))
else:

    def sh(a, b):
        return "(" + a.upper() + "|" + b.upper() + ")"
    def nt(a):
        return sh(a, a)
    def A(a):
        return "A" + str(a)
    def B(b):
        return "B" + str(b)

    def get(n):
        if n == 1:
            return "((A0|B0)|(A0|B0))"
        return sh(sh(get(n - 1), sh(nt(A(n - 1)), nt(B(n - 1)))), sh(A(n - 1), B(n - 1)))

    n = int(input())
    print(get(n))


'''
2
((((A0|B0)|(A0|B0))|((A1|A1)|(B1|B1)))|(A1|B1))

( ( X | ((A1|A1)|(B1|B1))) | (A1|B1) )


((((A0|B0)|(A0|B0))|((A1|A1)|(B1|B1)))|(A1|B1))    
 
'''
