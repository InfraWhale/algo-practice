import sys

k = int(sys.stdin.readline())

stk = []

for _ in range(k) :
    temp = int(sys.stdin.readline())
    if temp != 0 :
        stk.append(temp)
    else :
        stk.pop()

sum = 0

for num in stk :
    sum += num
    
print(sum)