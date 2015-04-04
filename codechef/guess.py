def odd(n):
    return (n+1)/2

def gcd(m, n):
    if (m == 0): return n
    return gcd(n % m, m)

T = int(raw_input())
for i in range(T):
    N, M = map(int, raw_input().split())
    numer = odd(N) * (M-odd(M)) + (N-odd(N)) * odd(M)
    denom = N*M
    g = gcd(numer, denom)
    print str(numer/g) + "/" + str(denom/g)
