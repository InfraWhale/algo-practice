import sys
n, k = map(int, sys.stdin.readline().split())

INF = float('Inf')
dp = [INF] * (k+1)
dp[0] = 0

coins = [int(sys.stdin.readline()) for _ in range(n)]
coins = list(set(coins))

for coin in coins :
        
    for i in range(coin, k+1) :
        if dp[i-coin] != INF :
            dp[i] = min(dp[i], dp[i-coin]+1)

if dp[k] == INF : # 이부분에서 실패 -> 문제를 잘 읽어야 한다!
    print(-1)
else :
    print(dp[k])