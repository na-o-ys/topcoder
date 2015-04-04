def calc(n):
    n0 = n
    while (n%2 == 0 or n%3 == 2):
        n -= 1
    return n0 - n

n = int(raw_input())
a = map(int, raw_input().split())
print sum(map(calc, a))
