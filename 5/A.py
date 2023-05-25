# doesn't work for some reason...

inp = open('automaton.in', 'r')
outp = open('automaton.out', 'w')

def readline():
    return inp.readline().rstrip()

n, S = readline().split()
n = int(n)

aut = {}
for _ in range(n):
    nt, arr, x = readline().split()
    if aut.get(nt) is None:
        aut[nt] = []
    aut[nt].append(x)

def check(v, s):
#    print('->', v, s)
    res = False
    for u in aut.get(v) or []:
        if u.islower(): #term 
            q = u == s
        else:
            if u[0] != s[0]:
                continue
            q = check(u[1:], s[1:])
        res = res or q
    return res


m = int(readline())
for _ in range(m):
    print('yes' if check(S, readline()) else 'no', file=outp)

inp.close()
outp.close()

# 
