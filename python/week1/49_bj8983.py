import sys

m, n, l = map(int,sys.stdin.readline().split())
arr_m = list(map(int, sys.stdin.readline().split())) # 사수 리스트
arr_n = [] # 동물 리스트
for i in range (n) :
    arr_n.append(tuple(map(int, sys.stdin.readline().split())))
arr_m.sort()
arr_n.sort()

for i in range(n) :
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

print(arr_n)
print(arr_m)