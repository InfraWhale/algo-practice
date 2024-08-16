# 살짝 헤맴

import sys, math

a = int(sys.stdin.readline())

def che(n) :
    if n == 1 :
        return False
    cnt = math.ceil(n**(1/2))
    for i in range (2, cnt+1) :
        if n !=i and n%i == 0 :
            return False
    return True


for i in range (a) :
    b = int(sys.stdin.readline())
    
    if b == 4 :
        print(2, 2)
        continue
    
    #홀수이면
    if(b//2 % 2) == 1 :
        start = (b//2)
    #짝수이면
    else :
        start = (b//2)+1
    
    for j in range (start, b, 2) :
        if(che(b-j) and che(j)) :
            print(b-j, j)
            break