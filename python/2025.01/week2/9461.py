import sys

t = int(sys.stdin.readline())

dp = [0 for i in range(100)]
dp[0] = 1
dp[1] = 1
dp[2] = 1
dp[3] = 2
dp[4] = 2

cnt = 5

for _ in range(t) :
    n = int(sys.stdin.readline())
    if cnt < n:
        start = cnt
        for i in range (start, n):
            dp[i] = dp[i-1] + dp[i-5]
            cnt += 1
    print(dp[n-1])