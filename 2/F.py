#!/usr/bin/env python3
n = int(input())
encoded = list(map(int, input().split()))
n = len(encoded)

d = {}
code = 0
for i in range(26): 
    d[i] = chr(ord('a') + i)
    code += 1

t = ''
ans = ''
i = 0


for j in range(len(encoded)):
    c = encoded[j]
    if c not in d:
        d[c] = t + d[encoded[j - 1]][0]
        ans += t
        t += d[encoded[j - 1]][0]
        code += 1
        continue

    for i in range(len(d[c])):
        if t + d[c][i] in d.values():
            t += d[c][i]
        else:
            ans += t
            d[code] = t + d[c][i]
            code += 1
            t = d[c][i]

ans += t

print(ans) 


#for e in d.keys():
#    if e >= 26:
#        print(str(e) + ": " + d[e])

'''
aaaaaaaaaa
0 26 27 28

6      
0 1 0 2 26 0

aaaabaabab
0 26 0 1 26 29 1 

4
0 1 26 28
abababa


cacacac

'''