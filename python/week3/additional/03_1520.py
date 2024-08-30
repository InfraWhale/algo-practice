import sys
sys.setrecursionlimit(10**6)
# 16% 시간초과 -> 36% 시간초과
dy = [-1, 0, 1, 0]
dx = [0, 1, 0 ,-1]

n, m = map(int, sys.stdin.readline().split())

arr = [list(map(int, sys.stdin.readline().split())) for y in range(n)]

dp = [[0 for x in range(m)] for y in range(n)]

# dp[0][0] = 1

def dfs (y, x) :    
    if dp[y][x] != 0 :
        return dp [y][x]
    
    if y == n-1 and x == m-1 :
        return 1
    
    
    for i in range(4) :
        ny = y + dy[i]
        nx = x + dx[i]
        
        if 0 <= ny < n and 0 <= nx < m and arr[ny][nx] < arr[y][x]:
            dp[y][x] += dfs(ny, nx) # 0으로 초기화 해줄 경우, dfs(ny, nx)의 값이 0일 때 다시 0이 들어가므로 나중에 계산을 또 해줘야 한다.
            # -1로 초기화하고 0일 경우엔 값을 바로 리턴할 것이다.
    
    return dp[y][x]
    
print(dfs(0, 0))
    