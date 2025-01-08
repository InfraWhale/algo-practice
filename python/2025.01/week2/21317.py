import sys

n = int(sys.stdin.readline())
arr_small = []
arr_big = []

for _ in range (n-1) :
    small, big = map(int, sys.stdin.readline().split())
    arr_small.append(small)
    arr_big.append(big)
k = int(sys.stdin.readline())

# print(arr_small)
# print(arr_big)

dp = [[float('Inf') for _ in range (n+1)] for _ in range (2)]
dp[0][0] = 0

# print(dp)

for i in range (1, n) :
    if i - 1 >= 0 :
        dp[0][i] = min(dp[0][i-1] + arr_small[i-1], dp[0][i])
        dp[1][i] = min(dp[1][i-1] + arr_small[i-1], dp[1][i])
    if i - 2 >= 0 :
        dp[0][i] = min(dp[0][i-2] + arr_big[i-2], dp[0][i])
        dp[1][i] = min(dp[1][i-2] + arr_big[i-2], dp[1][i])
    if i - 3 >= 0 :
        dp[1][i] = min(dp[0][i-3] + k, dp[1][i])
        
# print(dp)
print(min(dp[0][n-1], dp[1][n-1]))
        