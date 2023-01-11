#!/usr/bin/env python3

n = int(input())
a = list(map(int, input().split()))
s = int(input())

def getbit(x, i):
    return (x >> i) & 1;

vals = {}

'''
1   
1
4294967295
32: (1)|(~1)
33: Impossible
'''

for bit in range(33): #32
    val = tuple(map(lambda x: getbit(x, bit), a))
    if vals.get(val) != None:
        if vals[val] != getbit(s, bit):
            print("Impossible")
            exit(0)
    vals[val] = getbit(s, bit)

ones = list(vals.values()).count(1)
if ones == 0:
    print("~1&1")
    exit(0)


braces = []
for inputs in vals.keys():
    if vals[inputs] == 0:
        continue
    s = ''
    for var in range(n):
        if inputs[var]:
            s += str(var + 1)
        else:
            s += '~' + str(var + 1)
        if var != n - 1:
            s += '&'
    if ones > 1: # there will be more than 1 element in 50:join
        s = '(' + s + ')'
    braces.append(s)

print('|'.join(braces))