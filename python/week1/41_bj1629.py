# 정답인 코드

import sys
sys.setrecursionlimit(10**6)
a, b, c = map(int,sys.stdin.readline().split())

# ((x % n) * (y % n)) % n = (x * y) % n
#  (x^s * x) % n = ((x^s % n) * (x % n)) % n

# call = 0

def go(x, y, z) :
    # global call
    # call = call + 1
    if y == 1 :
        return x % z
    div = y//2
    ret = go(x, div, z)
    ret = ret * ret % z
    
    #y가 홀수일때 남은 1 처리해줘야 함
    if (y % 2) == 1 :
        ret = ret * (x % z) % z

    return ret

print(go(a, b, c))
# print("call : ", call)
