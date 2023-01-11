#!/usr/bin/env python3

def gen(n, p=[]):
	if len(p) == n:
		print(*p) #return
	for i in range(1, n + 1):
		if i not in p:
			gen(n, p + [i])

n = int(input())
gen(n)