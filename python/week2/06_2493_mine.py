import sys
#63퍼 시간초과
n = int(sys.stdin.readline())
stk = list(map(int, sys.stdin.readline().split()))
arr = [0]*n

for i in range (n) :
    cnt = 0
    max_val = 0
    now = stk[i]
    for j in range(i+1, n) :
        if stk[j] > now :
            break
        elif max_val > now:
            continue
        else :
            max_val = now
            arr[j] = i+1
            
for i in arr :
    print(arr[i], end=' ')