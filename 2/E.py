#!/usr/bin/env python3

s = input()
d = {}
code = 0
for i in range(26): #26
    d[chr(ord('a') + i)] = i
    code += 1

t = ''
ans = []
for c in s:
    if t + c in d:
        t += c
    else:
        ans.append(d[t])
        d[t + c] = code
        code += 1
        t = c

ans.append(d[t])
print(*ans)

#for e in d.keys():
#    if d[e] >= 26:
#        print(str(e) + ": " + str(d[e]))
