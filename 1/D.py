#!/usr/bin/env python3
import math, random

def last(a):
    return len(a) - 1;

def NOT(i):
    return "1 %d" % (i + 1)
def AND(i, j):
    return "2 %d %d" % (i + 1, j + 1)
def OR(i, j):
    return "3 %d %d" % (i + 1, j + 1)

n = int(input()) # !!! n>=2
#n = 10
a = []
for i in range(2 ** n):
    s, r = input().split()
    s = list(map(int, s))
    r = int(r)

#    r = random.randint(0, 1)
#    s = bin(i)[2:].zfill(n)
    
    a.append((s, r))

scheme = ["VAR " + str(i + 1) for i in range(n)]
conjs = []

for i in range(2 ** n):
    s, r = a[i]
    if not r:
        continue
    #conjunction = s
    #on position i: 0 - negation of variable i, 1 - variable i
    #AND between each pair of vars

    var_loc = [i for i in range(n)]
    for i in range(len(s)):
        if s[i] == 0:
            scheme.append(NOT(i))
            var_loc[i] = last(scheme)

    scheme.append(AND(var_loc[0], var_loc[1])) # ok, n>1
    for i in range(2, len(s)):
        scheme.append(AND(var_loc[i], last(scheme)))

    conjs.append(last(scheme))

if len(conjs) > 1:
    scheme.append(OR(conjs[0], conjs[1]))
    for i in range(2, len(conjs)):
        scheme.append(OR(conjs[i], last(scheme)))


if len(scheme) == n: # all function results are zeros
    scheme.append(NOT(0))
    scheme.append(AND(0, last(scheme)))

print(len(scheme))
for line in scheme[n:]:
    print(line)



'''
3
000 0
001 0
010 0
011 0
100 1
101 0
110 1
111 1


14                                                           
1 2
1 3                    
2 1 4
2 5 6                                                    
1 3
2 1 2
2 8 9
2 1 2
2 3 11
3 7 10
3 12 13

14
1   VAR 1
2   VAR 2 
3   VAR 3
4   1 2
5   1 3
6   2 1 4
7   2 5 6
8   1 3
9   2 1 2
10  2 8 9
11  2 1 2
12  2 3 11
13  3 7 10
14  3 12 13


14
1   VAR
2   VAR
3   VAR
4   NOT 2
5   NOT 3
6   AND 1 4
7   AND 5 6
8   NOT 3
9   AND 1 2
10  AND 8 9
11  AND 1 2
12  AND 3 11
13  OR 7 10
14  OR 12 13


'''
