import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
arr = [list(map(int, sys.stdin.readline().rstrip())) for _ in range (n)]
visited = [[0]*m for _ in range (n)]

dy =[-1, 0, 1, 0]
dx =[0, 1, 0, -1]

def bfs(y, x) :
    que = deque([(y, x)])
    visited[y][x] = 1
    while que :
        now_y, now_x = que.popleft()
        
        if now_y == n-1 and now_x == m-1 :
            print (visited[now_y][now_x])
            break

        for i in range (4) :
            ny = now_y+dy[i]
            nx = now_x+dx[i]
            
            if ny >= n or ny < 0 or nx >= m or nx < 0 or visited[ny][nx] != 0 or arr[ny][nx] == 0:
                continue
            visited[ny][nx] = visited[now_y][now_x] + 1
            que.append((ny, nx))
    return

bfs(0, 0)