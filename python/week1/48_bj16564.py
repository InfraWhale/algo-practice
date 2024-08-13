import sys

n, k = map(int,sys.stdin.readline().split())
arr = []
for i in range (n) :
    arr.append(int(sys.stdin.readline()))

arr.sort()
sum = arr[0]

for i in range(n-1) :
    cnt = i+1
    minus = arr[i+1] -arr[i]
    if minus == 0 :
        continue
    if cnt * minus <= k :
        sum += minus
        k -= cnt * minus
    else :
        sum += k // cnt
        k = 0
        break
    
if k > 0 :
    sum += k // n

print(sum)