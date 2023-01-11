#!/usr/bin/env python3

s = input()
a = []
for i in range(len(s)):
	a.append(s[i:] + s[:i])

print(''.join(map(lambda s: s[-1], sorted(a))))