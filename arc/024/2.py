N = int(raw_input())
c = [0]*N
for i in range(N): c[i] = int(raw_input())
pos = -1
for i in range(N-1):
    if c[i] != c[i+1]: 
        pos = i+1
        break
if pos == -1:
    print -1
    exit()

maxlen = 0
cnt = 1
for i in range(N):
    if c[(pos+i)%N] != c[(pos+i+1)%N]:
        if cnt >= 3: maxlen = max(maxlen, cnt)
        cnt = 1
    else: cnt += 1
print (maxlen-1) / 2 + 1
