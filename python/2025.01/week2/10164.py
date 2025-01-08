import sys # 36%

n, m, k = map(int, sys.stdin.readline().split())

start = (0, 0)

def case(end) :
    dp = [[0 for _ in range(end[1])] for _ in range(end[0])]

    for i in range(end[0]) :
        dp[i][0] = 1
    for j in range(end[1]) :
        dp[0][j] = 1

    for i in range (1, end[0]) :
        for j in range(1, end[1]) :
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
            
    # print(dp)
            
    return dp[end[0]-1][end[1]-1]

if k == 0 :
    end = (n, m)
else :
    row = (k // m) + 1
    column = k % m
    end = (row, column)
    # print(end)
    
ret1 = case(end)

if k == 0 :
    ret2 = 1
else :
    end = (n-row+1, m-column+1)
    
    ret2 = case(end)

print(ret1*ret2)