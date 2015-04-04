import string
N, K = map(int, raw_input().split())
S = raw_input()
chars = [S.count(c) for c in string.ascii_lowercase]
arr = [(chars, 0)]
for i in range(1, N-K):
    chars = chars[:]
    chars[ord(S[i-1])-ord('a')] -= 1
    chars[ord(S[i+K-1])-ord('a')] += 1
    arr.append((chars, i))
arr.sort()
a = arr[0]
for i in range(1, len(arr)):
    if a[0] == arr[i][0]:
        if abs(a[1] - arr[i][1]) >= K:
            print 'YES'
            exit()
    else: a = arr[i]
print 'NO'
