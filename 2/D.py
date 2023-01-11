#!/usr/bin/env python3

s = input()
alpha = ''.join(map(chr, range(ord('a'), ord('z') + 1)))
for c in s:
    i = alpha.index(c)
    print(i + 1, end=" ")
    alpha = alpha[i] + alpha[:i] + alpha[i + 1:]
print()