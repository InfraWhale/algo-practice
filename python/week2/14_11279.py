import sys
import heapq

# 최대 힙 이용

n = int(sys.stdin.readline())
max_heap = []

for i in range (n) :
    t = int(sys.stdin.readline())
    if t == 0 :
        if not max_heap :
            print(0)
        else :
            val = heapq.heappop(max_heap)
            print(val[1])
    else :
        heapq.heappush(max_heap, (-t, t))
    