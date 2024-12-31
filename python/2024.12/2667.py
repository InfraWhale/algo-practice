import sys

n = int(sys.stdin.readline())

arr = [list(map(int, sys.stdin.readline().rstrip())) for _ in range (n)]

visited = [[0 for _ in range(n)] for _ in range(n)]

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
arr_ret = []

def dfs (y, x) :
    global cnt
    visited[y][x] = 1
    cnt += 1
    
    for i in range (4) :
        ny = y+dy[i]
        nx = x+dx[i]
        
        if ny<0 or ny >=n or nx<0 or nx>=n or visited[ny][nx] == 1 or arr[ny][nx] == 0 :
            continue 
        dfs(ny, nx)
        
    return

for i in range(n) :
    for j in range(n) :
        if visited[i][j] == 0 and arr[i][j] == 1 :
            cnt = 0
            dfs(i, j)
            arr_ret.append(cnt)

arr_ret.sort()

print(len(arr_ret))
for i in range(len(arr_ret)) :
    print(arr_ret[i])