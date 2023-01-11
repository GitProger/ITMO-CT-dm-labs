#!/usr/bin/env python3

def get(n):
	if n == 1:
		return ['0', '1']
	p = get(n - 1)
	return list(map(lambda x: '0' + x, p)) + list(map(lambda x: '1' + x, p[::-1]))

print('\n'.join(get(int(input()))))