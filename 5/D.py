# TL
import sys, os
sys.setrecursionlimit(100000)

def memoize(f):
    tab = {}
    def f_mod(*x): # x, x <--> tuple([*x]), *x
        if tab.get(tuple([*x])) == None:
            tab[tuple([*x])] = f(*x)
        return tab[tuple([*x])]
    return f_mod

MOD = 1000000007
N = 100

inp = sys.stdin
outp = sys.stdout

if os.environ.get("USERNAME") != 'alex':
    inp = open('nfc.in', 'r')
    outp = open('nfc.out', 'w')

def readline():
    return inp.readline().rstrip()


n, S = readline().split()
n = int(n)

aut = {}
for _ in range(n):
    nt, arrow, s = readline().split()
    if aut.get(nt) is None:
        aut[nt] = []
    aut[nt].append(s)
 
w = readline()

@memoize
def get(v, l, r):
    ans = 0
    for cur in aut[v]:
        if len(cur) == 1: # term
            if w[l:r] == cur[0]:
                ans = (ans + 1) % MOD
        else:
            for i in range(l + 1, r):
                ans += get(cur[0], l, i) * get(cur[1] if len(cur) > 1 else 'a', i, r)
                ans %= MOD
    return ans

print(get(S, 0, len(w)), file=outp)


inp.close()
outp.close()
