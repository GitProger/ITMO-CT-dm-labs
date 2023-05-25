import sys
import functools

inp = sys.stdin
outp = sys.stdout

inp = open('epsilon.in', 'r')
outp = open('epsilon.out', 'w')

def memoize(f):
    tab = {}
    def f_mod(*x):
        if tab.get(tuple([*x])) == None:
            tab[tuple([*x])] = f(*x)
        return tab[tuple([*x])]
    return f_mod


def readline():
    return inp.readline().rstrip()

n, S = readline().split()
n = int(n)

aut = {}
nterm = set()
for _ in range(n):
    nt, arr, *x = readline().split()
    nterm.add(nt)
    if aut.get(nt) is None:
        aut[nt] = []
    aut[nt].append(x[0] if x else "")

# cycles

@memoize
def check(v):
    res = False
    for u in aut.get(v) or []:
        if u == "":
            return True
        if not u.isupper():
            continue
        res = res or functools.reduce(lambda a, b: a and b, map(check, u))
    return res

print('\n'.join(filter(check, sorted(nterm))), file=outp)

inp.close()
outp.close()

