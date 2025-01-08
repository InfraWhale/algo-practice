import sys

n, m, k = map(int, sys.stdin.readline().split())

def case(end):
    dp = [[0 for _ in range(end[1] + 1)] for _ in range(end[0] + 1)]

    for i in range(end[0] + 1):
        dp[i][0] = 1
    for j in range(end[1] + 1):
        dp[0][j] = 1

    for i in range(1, end[0] + 1):
        for j in range(1, end[1] + 1):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

    return dp[end[0]][end[1]]

if k == 0:
    ret1 = case((n - 1, m - 1))
    ret2 = 1
else:
    if k % m == 0:
        row = k // m
        column = m
    else:
        row = k // m + 1
        column = k % m

    ret1 = case((row - 1, column - 1))
    ret2 = case((n - row, m - column))

print(ret1 * ret2)