import sys

n, c = map(int,sys.stdin.readline().split())
arr = []
for i in range (n) :
    arr.append(int(sys.stdin.readline()))

arr.sort()

low_dist = 1
high_dist = arr[n-1] - arr[0]
max_val = 0

while (high_dist >= low_dist) :
    mid = (high_dist + low_dist) // 2
    prev = 0
    cnt = c-1
    for i in range (1, n) :
        if arr[i] - arr[prev] >= mid :
            cnt -= 1
            prev = i
    
    if cnt <= 0 : # cnt 0이면 좀더 키워보기
        max_val = mid
        low_dist = mid + 1
    else : # 아니라면 줄여보기
        high_dist = mid -1

print(max_val)