import math
def dist(p1, p2):
    dx = abs(p1[0]-p2[0])
    dy = abs(p1[1]-p2[1])
    return math.sqrt(dx*dx + dy*dy)

x0, y0, x1, y1, T, V = map(int, raw_input().split())
n = int(raw_input())
P = [] * n
for i in range(n):
    x, y = map(int, raw_input().split())
    d = dist((x, y), (x0, y0)) + dist((x, y), (x1, y1))
    if (d <= T * V):
        print 'YES'
        exit()
print 'NO'
