import sys, math

a = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().split()))
ret = 0

#짝수도 2 말고는 소수가 아닐 것이다. 이거 추가하면 더 효율적일듯
def che(n) :
    if n == 1 :
        return False
    cnt = math.ceil(n**(1/2))
    for i in range (2, cnt+1) :
        if n !=i and n%i == 0 :
            return False
    return True


for i in range (a) :
    if(che(arr[i])) :
        ret+= 1

print(ret)
