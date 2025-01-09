import sys

t = int(sys.stdin.readline())

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def check_row_column(y, x, num) :
    global r, c
    row_start = max(0, x-num)
    row_end = min(c-1, x+num)
    col_start = max(0, y-num)
    col_end = min(r-1, y+num)
    
    for i in range(row_start, row_end+1) :
        if i == x :
            continue
        if arr[y][i] == num :
            return False
    
    for i in range(col_start, col_end+1) :
        if i == y :
            continue
        if arr[i][x] == num :
            return False      
    return True

def check_count(num) :
    if arr_count[num] == 1 :
        return False
    arr_count[num] = 1
    return True

def dfs (y, x) :
    global r, c
    
    visited[y][x] = 1
    if not check_row_column(y, x, arr[y][x]) :
        return False
    
    if not check_count(arr[y][x]) :
        return False
    
    for i in range(4) :
        if not descr[y][x] & (1 << i) :
            continue
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or ny >= r or nx < 0 or nx >= c or visited[ny][nx] == 1:
            continue
        if not dfs(ny, nx) :
            return False
        
    return True

for _ in range(t) :
    r, c = map(int, sys.stdin.readline().split())
    
    arr = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(r)]
    descr = [list(map(int, sys.stdin.readline().split())) for _ in range(r)]
    
    visited = [[0 for _ in range(c)] for _ in range(r)]
    
    flag = True
    for i in range(r) :
        for j in range(c) :
            if visited[i][j] == 1 :
                continue
            arr_count = [0 for _ in range(9)]
            flag = dfs(i, j)
            if not flag :
                break
        if not flag :
            break   
    
    if flag :
        print("valid")
    else :
        print("invalid")