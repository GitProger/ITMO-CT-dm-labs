#!/usr/bin/env python3

n = int(input())
ans = []
for i in range(2 ** n):
    s = bin(i)[2:].zfill(n)
    if '11' in s:
    	continue
    ans.append(s)

print(len(ans)) # fibonacci number
for e in ans:
	print(e)