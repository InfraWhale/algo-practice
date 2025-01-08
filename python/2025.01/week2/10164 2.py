import sys # 36%

n, m, k = map(int, sys.stdin.readline().split())

if k != 0 :
    row = (k // m)
    column = k % m - 1

dp = [[0 for _ in range(m)] for _ in range(n)]

for i in range(n) :
    dp[i][0] = 1
for j in range(m) :
    dp[0][j] = 1

for i in range(1, n) :
    for j in range(1, m) :
        if k != 0 :
            if (i < row and j > column or i > row and j < column) :
                continue
            
            if i == row and j > column:
                dp[i][j] = dp[i][j-1]
            elif j == column and i > row:
                dp[i][j] = dp[i-1][j]
            else :
                dp[i][j] = dp[i][j-1] + dp[i-1][j]
        else :
            dp[i][j] = dp[i][j-1] + dp[i-1][j]

# print(row, column)
# print(dp)
print(dp[n-1][m-1])