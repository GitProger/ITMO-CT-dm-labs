#!/usr/bin/env python3

def gen(n, k, p=[]):
	if k == len(p):
		print(*p) #return
	for i in range(p[-1] if len(p) > 0 else 1, n + 1):
		if i not in p:
			gen(n, k, p + [i])

n, k = map(int, input().split())
gen(n, k)