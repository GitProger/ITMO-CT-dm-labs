#!/usr/bin/env python3
def prev(x):
    s = list(x)
    for i in range(len(s) - 1, -1, -1):
        if s[i] == '1':
            s[i] = '0'
            return ''.join(s)
        else:
            s[i] = '1'
    return '-'

def next(x):
    s = list(x)
    for i in range(len(s) - 1, -1, -1):
        if s[i] == '0':
            s[i] = '1'
            return ''.join(s)
        else:
            s[i] = '0'
    return '-'


s = input()
print(prev(s))
print(next(s))

'''

'''
