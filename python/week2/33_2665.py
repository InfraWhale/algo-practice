import sys
from collections import deque

n = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().rstrip())) for _ in range (n)]
visited = [[0]*n for _ in range (n)]

dy =[-1, 0, 1, 0]
dx =[0, 1, 0, -1]

def bfs(c, y, x) :
    dq = deque([(y, x)])
    visited[y][x] = 1
    if c == 0 :
        visited[y][x] += 1
    while dq :
        now_y, now_x = dq.popleft()
        
        for i in range (4) :
            ny = now_y+dy[i]
            nx = now_x+dx[i]
            
            if ny >= n or ny < 0 or nx >= n or nx < 0 or visited[ny][nx] != 0:
                continue
            if arr[ny][nx] == 1 :
                visited[ny][nx] = visited[now_y][now_x]
                dq.appendleft((ny, nx))
            else :
                visited[ny][nx] = visited[now_y][now_x] + 1
                dq.append((ny, nx))
    return

bfs(arr[0][0], 0, 0)
print(visited[n-1][n-1]-1)