#!/usr/bin/env python3
 
n = int(input())
a = list(map(int, input().split()))
s = int(input())
f = [-1 for i in range(2 ** n)]
 
for _ in range(33):
    bitres = 0        # result of the final oper for each bit
    for i in range(n):
        bitres = 2 * bitres + a[i] % 2
        a[i] //= 2
#    print(bitres)
    if f[bitres] == -1 or f[bitres] == s % 2:
        f[bitres] = s % 2 # corresponding s bit
        s //= 2
    else:
        print("Impossible")
        exit(0)
'''
20 0010100
 8 0001000
   0021200
'''
#print(f)
 
ones = f.count(1)
if ones == 0:
    print("~1&1")
    exit(0)
 
# ( & & )|( & & )|( & & )
 
braces = 0
for i in range(len(f)):
    if f[i] != 1: continue
         
    if ones > 1:
        if braces > 0: 
            print("|", end='')
        print("(", end='');
         
    cur = i;
    for k in range(n, 0, -1):
        if cur % 2 == 0:
            print("~", end='')
            
        print(k, end='')
        if k != 1:
            print("&", end='')            
        cur //= 2
     
    if ones > 1:
        print(")", end='')
             
    braces += 1
     
print()