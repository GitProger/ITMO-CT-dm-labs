import sys

inp = sys.stdin
outp = sys.stdout

inp = open('epsilon.in', 'r')
outp = open('epsilon.out', 'w')

def readline():
    return inp.readline().rstrip()

n, S = readline().split()
n = int(n)

ans = {}

aut = []
for _ in range(n):
    nt, arrow, *x = readline().split()
    x = x[0] if x else ""
    if x == "":
        ans[nt] = 1
    aut.append((nt, x))
 
# cycles

while True:
    change = False
    for p in aut:
        if not ans.get(p[0]):
            ok = True
            for v in p[1]:
                if not ans.get(v):
                    ok = False
                    break
            if ok:
                ans[p[0]] = 1
                change = True
    if not change:
        break


print(' '.join(sorted(ans.keys())), file=outp)

inp.close()
outp.close()

