import sys

n, k = map(int, sys.stdin.readline().split())

dp = [0] * (k+1)
dp[0] = 1

for _ in range (n) :
    coin = int(sys.stdin.readline())
    
    for i in range(coin, k+1) :
        dp[i] += dp[i-coin]

print(dp[k])