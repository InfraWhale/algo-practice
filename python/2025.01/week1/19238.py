import sys # 1% 틀렸습니다. -> 맞았습니다.
# 손님번호가 적은 순으로 태우게끔 되어있었음 -> 행 번호, 열 번호 작은 순으로 태우게끔
# 
from collections import deque
import heapq

n, m, fuel = map(int, sys.stdin.readline().split())
arr_map = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]
taxy_y, taxy_x = map(int, sys.stdin.readline().split())
taxy_y -= 1
taxy_x -= 1
arr_cust = []

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

for i in range (m) :
    a, b, c, d = (map(int, sys.stdin.readline().split()))
    arr_map[a-1][b-1] = i+2
    arr_cust.append((c-1, d-1))
    
# print(arr_map)

ret_flag = True
for _ in range (m) :
    
    if arr_map[taxy_y][taxy_x] > 1:
        start = (taxy_y, taxy_x, arr_map[taxy_y][taxy_x])
    else :
        visited = [[0 for _ in range(n)] for _ in range(n)]
        dist = 0
        find_flag = False
        find_heap = []
        queue = deque([(taxy_y, taxy_x)])
        visited[taxy_y][taxy_x] = 1
        while queue :
            dist += 1
            # print(queue)
            for _ in range(len(queue)) :
                now = queue.popleft()
                for i in range (4) :
                    ny = now[0] + dy[i]
                    nx = now[1] + dx[i]
                    if ny >= n or ny < 0 or nx >= n or nx < 0 or arr_map[ny][nx] == 1 or visited[ny][nx] == 1 :
                        continue
                    visited[ny][nx] = 1
                    if arr_map[ny][nx] > 1:
                        heapq.heappush(find_heap, (ny, nx, arr_map[ny][nx]))
                        # print("find customer : ", now[0], now[1])
                        find_flag = True
                    queue.append((ny, nx))
            if find_flag :
                break
        
        fuel -= dist
        # print("fuel : ", fuel)
        if fuel <= 0 or not find_flag :
            print(-1)
            ret_flag = False
            break
        # print("heapq : ", find_heap)
        start = heapq.heappop(find_heap)
    
    # print("selected customer : ", start[0], start[1], start[2])
    arr_map[start[0]][start[1]] = 0
    end = arr_cust[start[2]-2]
    
    visited = [[0 for _ in range(n)] for _ in range(n)]
    dist = 0
    find_flag = False
    queue = deque([(start[0], start[1])])
    visited[start[0]][start[1]] = 1
    while queue :
        dist += 1
        # print(queue)
        for _ in range(len(queue)) :
            now = queue.popleft()
            for i in range (4) :
                ny = now[0] + dy[i]
                nx = now[1] + dx[i]
                if ny >= n or ny < 0 or nx >= n or nx < 0 or arr_map[ny][nx] == 1 or visited[ny][nx] == 1 :
                    continue
                visited[ny][nx] = 1
                if ny == end[0] and nx == end[1]:
                    find_flag = True
                    # print("deliver customer : ", ny, nx)
                    break
                else :
                    queue.append((ny, nx))
        if find_flag :
            break
    
    fuel -= dist
    # print("dist : ", dist)
    # print("fuel : ", fuel)
    if fuel < 0 or not find_flag :
        print(-1)
        ret_flag = False
        break
    
    fuel += (dist*2)
    # print("new fuel : ", fuel)
    taxy_y = end[0]
    taxy_x = end[1]

if ret_flag == True :
    print(fuel)