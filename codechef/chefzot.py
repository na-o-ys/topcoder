N = int(raw_input())
A = map(int, raw_input().split())
l = 0
ans = 0
for i in range(N):
    if (A[i] == 0):
        l = 0
    else:
        l += 1
    ans = max(ans, l)
print ans
