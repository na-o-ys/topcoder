from itertools import chain
N = int(raw_input())
ys = [[] for i in range(1001)]
for i in range(N):
    x, y = map(int, raw_input().split())
    ys[x].append(y)

ans = []
def rec(l, r):
    if l >= r-1: return
    m = (l + r) / 2
    ls = [ys[x] for x in range(l,r) if len(ys[x])]
    se = set(reduce(lambda a, b: a+b, ls))
    ls = filter(lambda y: not(y in ys[m]), se)
    for y in ls:
        ans.append((m, y))
    rec(l, m)
    rec(m+1, r)

rec(1, 1001)
print len(ans)
for a in ans:
    print a[0], a[1]
