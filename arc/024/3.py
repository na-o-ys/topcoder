import string
N, K = map(int, raw_input().split())
S = raw_input()

chars = [S[0:K].count(c) for c in string.ascii_lowercase]
d = {tuple(chars): 0}
for i in range(1, N-K+1):
    chars[ord(S[i-1])-ord('a')] -= 1
    chars[ord(S[i+K-1])-ord('a')] += 1
    idx = d.get(tuple(chars))
    if idx != None:
        if i - idx >= K:
            print 'YES'
            exit()
    else:
        d.update({tuple(chars): i})
else: print 'NO'
