import sys
from collections import deque

r, c = map(int, sys.stdin.readline().split())

arr = [['' for x in range(c)] for y in range(r)]
visited = [[0 for x in range(c)] for y in range(r)]
visited_water = [[0 for x in range(c)] for y in range(r)]
water_list = []

for i in range (r) :
    temp = sys.stdin.readline().strip()
    for j in range (c) :
        arr[i][j] = temp[j]
        if temp[j] == '*' :
            water_list.append((i, j))
            visited_water[i][j] = 1
        elif temp[j] == 'S' :
            start = (i, j)
        elif temp[j] == 'D' :
            end = (i, j)

dy =[-1, 0, 1, 0]
dx =[0, 1, 0, -1]

def bfs() :
    global flag
    time = 0
    que = deque([start])
    water_que = deque(water_list)
    while que :
        time += 1
                
        for _ in range(len(water_que)) :
            
            now_y, now_x = water_que.popleft()
            for i in range (4) :
                ny = now_y+dy[i]
                nx = now_x+dx[i]
                if ny >= r or ny < 0 or nx >= c or nx < 0 or visited_water[ny][nx] == 1 or arr[ny][nx] == 'D' or arr[ny][nx] == 'X':
                    continue
                visited_water[ny][nx] = 1
                water_que.append((ny, nx))
                
        for _ in range(len(que)) :
            
            now_y, now_x = que.popleft()
            
            for i in range (4) :
                ny = now_y+dy[i]
                nx = now_x+dx[i]
                if (ny, nx) == end :
                    print(time)
                    exit()
                if ny >= r or ny < 0 or nx >= c or nx < 0 or visited[ny][nx] == 1 or visited_water[ny][nx] == 1 or arr[ny][nx] == 'X':
                    continue
                visited[ny][nx] = 1
                que.append((ny, nx))
    return

bfs()

print("KAKTUS")