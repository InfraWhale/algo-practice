import sys
from collections import deque
# 시간초과...
m, n, h = map(int, sys.stdin.readline().split())

arr = [[[0 for x in range(m)] for y in range(n)] for z in range(h)]
tom_cnt = 0
max_val = 0

for i in range (h) :
    for j in range (n) :
        arr[i][j] = list(map(int, sys.stdin.readline().split()))
        tom_cnt += arr[i][j].count(0)
#arr = [[list(map(int, sys.stdin.readline().split())) for _ in range (n)] for __ in range (h)] # arr[h][n][m]
visited = [[[0 for x in range(m)] for y in range(n)] for z in range(h)]

#안익은 토마토가 없으면 바로 0 출력하고 종료
if tom_cnt == 0 :
    print(0)
    exit()

dz =[-1, 0, 0, 1, 0, 0]
dy =[0, -1, 0, 0, 1, 0]
dx =[0, 0, -1, 0, 0, 1]

def bfs(z, y, x) :
    que = deque([(z, y, x)])
    visited[z][y][x] = 1
    while que :
        now_z, now_y, now_x = que.popleft()
        
        for i in range (6) :
            nz = now_z+dz[i]
            ny = now_y+dy[i]
            nx = now_x+dx[i]
            
            if  nz >= h or nz < 0 or ny >= n or ny < 0 or nx >= m or nx < 0 or arr[nz][ny][nx] != 0:
                continue
            if visited[nz][ny][nx] != 0 and visited[nz][ny][nx] <= visited[now_z][now_y][now_x]+1 :
                continue
            if visited[nz][ny][nx] == 0 :
                tom_cnt -= 1
            visited[nz][ny][nx] = visited[now_z][now_y][now_x] + 1
            # print(visited)
            que.append((nz, ny, nx))
    return

for i in range (h) : # for문 전부 돌면서 bfs
    for j in range (n) :
        for k in range(m) :
            if visited[i][j][k] or arr[i][j][k] != 1:
                continue
            bfs(i, j, k)

for i in range (h) :
    for j in range (n) :
        for k in range(m) :
            if arr[i][j][k] == 0 and visited[i][j][k] == 0 : # 토마토가 남았으면 -1 출력
                print(-1)
                exit()
            else :
                max_val = max(visited[i][j][k], max_val)
                
print(max_val-1)