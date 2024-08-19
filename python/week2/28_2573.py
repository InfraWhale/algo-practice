import sys
sys.setrecursionlimit(10**6)
# 96% 틀렸습니다. -> ice_cnt 2이면 break 연쇄로 타는 것이 아니라 바로 exit() 하도록 변경
# 반례모음 https://forward-gradually.tistory.com/67 (2번으로 하면 예전 코드가 터졌다.)

dy =[-1, 0, 1, 0]
dx =[0, 1, 0, -1]

n, m = map(int, sys.stdin.readline().split())
arr = []*n
total_ice = 0
loop_cnt = 0
for i in range(n) :
    arr.append(list(map(int,sys.stdin.readline().split())))
    total_ice += sum(arr[i])
visited = []

def dfs(y, x) :
    
    visited[y][x] = 1
    arr[y][x] = check_water(y, x, arr[y][x])
    
    for i in range(4) :
        ny = y+dy[i]
        nx = x+dx[i]
        if visited[ny][nx] == 1 or arr[ny][nx] == 0:
            continue
        dfs(ny, nx)
    return

def check_water(y, x, arr_val) :
    global total_ice
    cnt = 0
    for i in range(4) :
        ny = y+dy[i]
        nx = x+dx[i]
        if visited[ny][nx] == 0 and arr[ny][nx] == 0:
            cnt += 1
    cnt = min(cnt, arr_val)
    total_ice -= cnt
    return arr_val - cnt

while total_ice > 0 :
    ice_cnt = 0 # 분리구간의 갯수

    visited = [[0]*m for _ in range (n)]
    for i in range (n) :
        for j in range (m):
            if arr[i][j] == 0 or visited[i][j] == 1 :
                continue
            dfs(i, j)
            ice_cnt += 1
            if ice_cnt == 2 :
                print(loop_cnt)
                exit()
    loop_cnt += 1
print(0)
