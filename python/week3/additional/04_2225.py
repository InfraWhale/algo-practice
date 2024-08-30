import sys
n, k = map(int, sys.stdin.readline().split())

dp = [[0 for _ in range(k+1)] for _ in range (n+1)]

dp[0][0] = 1

for i in range (k) :
    
    for j in range (0, n+1) : # 만들어야 하는 수
        
        for l in range (0, j+1) : # 더해지는 수
        
            dp[j][i+1] += dp[j-l][i]

print(dp[n][k] % 1000000000)