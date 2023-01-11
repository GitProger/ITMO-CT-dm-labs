def get(n, output=False):
    s = set()
    for i in range(1 << n):
        b = bin(i)[2:].zfill(n)
        if b.count('0') % 2 == 1:
            continue
        mn = b
        for i in range(n):
            if b[i:] + b[:i] < mn:
                mn = b[i:] + b[:i]
        if output and mn not in s:
            print(mn.replace('0', '2'))
        s.add(mn)
    return len(s)

print(get(16))