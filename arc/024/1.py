L, R = map(int, raw_input().split())
l = map(int, raw_input().split())
r = map(int, raw_input().split())
sl = [l.count(i) for i in range(10, 41)]
sr = [r.count(i) for i in range(10, 41)]
ans = 0
for i in range(31):
    ans += min(sl[i], sr[i])
print ans
