#!/usr/bin/env python3

def get(n, k):
	if n == 1:
		return [list(map(str, range(k)))]
	p = get(n - 1, k)
	pr = p[::-1]
	return sum(map(lambda i: 
		       list(map(
		       	    lambda x: str(i) + x, p if i % 2 == 0 else pr)), 
		            range(k)),
		       start=[])

n, k = map(int, input().split())
print('\n'.join(get(n, k)))
