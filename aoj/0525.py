import itertools
R, C = map(int, raw_input().split())
a = []
for i in range(R):
    a.append(map(int, raw_input().split()))

ans = 0
for pat in itertools.product((0, 1), repeat = R):
    rev = [[c^p for c in row]
            for (row, p) in zip(a, pat)]
    cols = zip(*rev)
    zeros = [c.count(0) for c in cols]
    points = [max(z, R-z) for z in zeros]
    ans = max(sum(points), ans)
print ans

# def rev(row):
#     return [1^v for v in row]
# 
# def count(m):
#     rm = zip(*m)
#     return sum([max(rm[c].count(0), rm[c].count(1)) for c in range(C)])
# 
# ans = 0
# for i in range(1 << R):
#     b = [a[r] if (i >> r) & 1 else rev(a[r]) for r in range(R)]
#     ans = max(ans, count(b))
# 
# print ans
