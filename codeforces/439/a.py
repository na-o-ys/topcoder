n, d = map(int, raw_input().split())
t = map(int, raw_input().split())

devu = sum(t) + (n-1) * 10
if (devu > d):
    print -1
    exit()

print (n-1) * 2 + (d - devu) / 5
