import sys
import heapq

dy = [0, 1, 0]
dx = [1, 0, -1]

n, m = map(int, sys.stdin.readline().split())

map = [list(map(int,sys.stdin.readline().split())) for i in range(n)]

INF = float('Inf')
dp =  [[-INF for x in range(m)] for y in range(n)]

visited = [[0 for x in range(m)] for y in range(n)]

maxq = []
heapq.heappush(maxq, (-map[0][0], 0, 0, -1, -1))
visited[0][0] = 1

while maxq : 
    cost, y, x, old_y, old_x = heapq.heappop(maxq)
    cost = -cost
    
    if y == 0 and x == 0 :
        dp[y][x] = cost
    else :
        dp[y][x] = dp[old_y][old_x] + cost
    
    for i in range (3) :
        ny = y + dy[i]
        nx = x + dx[i]
        
        if ny < 0 or ny >=n or nx < 0 or nx >= m or visited[ny][nx] == 1 :
            continue
        visited[ny][nx] = 1
        heapq.heappush(maxq, (-map[ny][nx], ny, nx, y, x))
        
print(dp)
        

