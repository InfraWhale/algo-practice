import sys

n, c = map(int,sys.stdin.readline().split())
arr = []
for i in range (n) :
    arr.append(int(sys.stdin.readline()))

arr.sort()

dist = (arr[n-1] - arr[0] - 1) // (c-1)
chunk = dist
max_val = 0

while (chunk > 0) :
    chunk //= 2
    prev = 0
    cnt = c-1
    for i in range (1, n) :
        if arr[i] - arr[prev] >= dist :
            cnt -= 1
            prev = i
    
    if cnt <= 0 : # cnt 0이면 좀더 키워보기
        max_val = dist
        dist += chunk
    else : # 아니라면 줄여보기
        dist -= chunk

print(max_val)