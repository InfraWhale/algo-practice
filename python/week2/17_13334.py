import sys
import heapq

n = int(sys.stdin.readline())

arr_pp = []

for _ in range(n)

min_heap = []
cnt = 0

for i in range (n) :
    heapq.heappush(min_heap, int(sys.stdin.readline()))

while len(min_heap) != 1 :
    first = heapq.heappop(min_heap)
    second = heapq.heappop(min_heap)
    cnt += (first+second)
    heapq.heappush(min_heap, first + second)

print(cnt)