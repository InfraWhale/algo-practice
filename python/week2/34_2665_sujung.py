import sys
from collections import deque
# 풀이법 변경
m, n, h = map(int, sys.stdin.readline().split())

arr = [[[0 for x in range(m)] for y in range(n)] for z in range(h)]
tom_cnt = 0 # 토마토 개수

one_list = []
visited = [[[-1 for x in range(m)] for y in range(n)] for z in range(h)]

for i in range (h) :
    for j in range (n) :
        temp = list(map(int, sys.stdin.readline().split()))
        for k in range (m) :
            arr[i][j][k] = temp[k]
            if temp[k] == 1 :
                one_list.append((i, j, k))
                visited[i][j][k] = 0
            elif temp[k] == 0 :
                tom_cnt += 1

#안익은 토마토가 없으면 바로 0 출력하고 종료
if tom_cnt == 0 :
    print(0)
    exit()

dz =[-1, 0, 0, 1, 0, 0]
dy =[0, -1, 0, 0, 1, 0]
dx =[0, 0, -1, 0, 0, 1]

def bfs() :
    global day
    global tom_cnt
    day = -1
    que = deque(one_list)
    while que :
        day += 1
        for i in range(len(que)) :
            
            now_z, now_y, now_x = que.popleft()
            for i in range (6) :
                nz = now_z+dz[i]
                ny = now_y+dy[i]
                nx = now_x+dx[i]
                if  nz >= h or nz < 0 or ny >= n or ny < 0 or nx >= m or nx < 0 or arr[nz][ny][nx] != 0 or visited[nz][ny][nx] != -1:
                    continue
                tom_cnt -= 1
                visited[nz][ny][nx] = day + 1
                que.append((nz, ny, nx))
    return

bfs()

if tom_cnt != 0 :
    print(-1)
else :
    print(day)