import sys
import heapq

n = int(sys.stdin.readline())
max_heap = [] # mid 보다 작은값 들어가는거
max_cnt = 0
min_heap = [] # mid 보다 큰값 들어가는거
min_cnt = 0

for i in range (n) :
    if i == 0 :
        mid = int(sys.stdin.readline())
        #print("mid:", mid)
        print(mid)
    else :
        num = int(sys.stdin.readline())
        if num >= mid :
            heapq.heappush(min_heap, num)
            min_cnt += 1
        else :
            heapq.heappush(max_heap, (-num, num))
            max_cnt += 1
        
        if min_cnt == max_cnt+2 :
            heapq.heappush(max_heap, (-mid, mid))
            mid = heapq.heappop(min_heap)
            min_cnt -= 1
            max_cnt += 1
        elif max_cnt == min_cnt+1 :
            heapq.heappush(min_heap, mid)
            mid = heapq.heappop(max_heap)[1]
            max_cnt -= 1
            min_cnt += 1
        # print("mid:", mid)
        print(mid)
    