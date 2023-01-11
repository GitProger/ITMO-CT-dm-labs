#!/usr/bin/env python3
#рефлексивными, антирефлексивными, симметричными, антисимметричными и транзитивными
 
def print_matrix(matrix):
    print('\n'.join(map(lambda x: ' '.join(map(str, x)), matrix)))
def impl(a, b):
    return (not a) or (a and b)
 
 
def get(a):
    n = len(a)
    refl, aref, sim, asim, tr = 1, 1, 1, 1, 1
    for i in range(n):
        for j in range(n):
            if a[i][i]:
                aref = 0
            else:
                refl = 0
            if a[i][j]:
                if i != j:
                    if not a[j][i]:
                        sim = 0
                    if a[j][i]:
                        asim = 0
            if tr and not a[i][j]:
                for k in range(n):
                    if a[i][k] and a[k][j]:
                        tr = 0
                        break
    return refl, aref, sim, asim, tr
 
 
n = int(input())
a1 = [list(map(int, input().split())) for _ in range(n)]
a2 = [list(map(int, input().split())) for _ in range(n)]
print(*get(a1))
print(*get(a2))
 
a3 = [[0 for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(n):
        for k in range(n):
            if a1[i][j] and a2[j][k]:
                a3[i][k] = 1
 
print_matrix(a3)