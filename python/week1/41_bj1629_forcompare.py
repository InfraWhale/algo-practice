import sys
sys.setrecursionlimit(10**6)
a, b, c = map(int,sys.stdin.readline().split())

# ((x % n) * (y % n)) % n = (x * y) % n  

call = 0

def go(x, y, z) :
    global call
    call = call + 1
    if y == 1 :
        return x % z
    div = y//2
    return (go(x, div, z) * go(x, y-div, z)) % z

print(go(a, b, c))
print("call : ", call)
