import sys

a = int(sys.stdin.readline())

def fac(n : int) -> int:
    if n == 0:
        return 1
    return n*fac(n-1)

print(fac(a))
