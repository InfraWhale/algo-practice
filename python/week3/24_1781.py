import sys
import heapq

n = int(sys.stdin.readline())
arr = [tuple(map(int, sys.stdin.readline().split())) for _ in range (n)]
max_q = []

max_time = max(arr, key=lambda x: x[0])[0]

arr.sort(key = lambda x : (-x[0], -x[1]))

sum = 0
point = 0
for time in range (max_time, 0, -1) :
    
    temp = point
    for i in range (point, n) :
        if arr[i][0] == time :
            heapq.heappush(max_q, (-arr[i][1]))
            temp += 1
        else :
            break
    point = temp
    
    if max_q :
        sum += -heapq.heappop(max_q)

print(sum)
