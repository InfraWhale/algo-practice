import sys #1% 시간초과 (그리디인줄?)
import heapq

n = int(sys.stdin.readline())

arr = []
day_count = [0 for _ in range (n+1)]

for start in range (1, n + 1) :
    days, cost = map(int, sys.stdin.readline().split())
    end = start + days - 1
    if end <= n :
        heapq.heappush(arr, (-(cost / days), -days, start, end, cost))

ret = 0

while arr :
    now = heapq.heappop(arr)
    if day_count[now[2]] == 1 or day_count[now[3]] == 1 :
        continue
    for i in range(now[2], now[3]+1) :
        day_count[i] = 1
    ret += now[4]

print(ret)