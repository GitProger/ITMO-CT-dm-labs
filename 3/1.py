#!/usr/bin/env python3
n = int(input())
print('\n'.join(map(lambda c: bin(c)[2:].zfill(n), range(2 ** n))))