#!/usr/bin/env python3
# https://neerc.ifmo.ru/wiki/index.php?title=%D0%A6%D0%B5%D0%BF%D0%BD%D1%8B%D0%B5_%D0%BA%D0%BE%D0%B4%D1%8B#:~:text=%D0%A6%D0%B5%D0%BF%D0%BD%D0%BE%D0%B9%20%D0%BA%D0%BE%D0%B4%20(%D0%B0%D0%BD%D0%B3%D0%BB.,%D0%B8%D0%B7%20%D0%BF%D1%80%D0%B5%D0%B4%D1%8B%D0%B4%D1%83%D1%89%D0%B5%D0%B3%D0%BE%20%D1%86%D0%B8%D0%BA%D0%BB%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B8%D0%BC%20%D1%81%D0%B4%D0%B2%D0%B8%D0%B3%D0%BE%D0%BC%20%D0%B2%D0%B2%D0%B5%D1%80%D1%85.
def getcode(n):
    cur = '0' * n
    res = [cur]
    was = {cur}
    while True:
        pref = cur[1:n]
        if pref + '1' not in was:
            cur = pref + '1'
        elif pref + '0' not in was:
            cur = pref + '0'
        else:
            break
        res.append(cur)
        was.add(cur)
    return res

print('\n'.join(getcode(int(input()))))