import sys # 1% 틀렸습니다.
from collections import deque

t = int(sys.stdin.readline())

for _ in range(t) :
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
    
    for i in range (1, n+1) :
        dp[i][i] = arr[i-1]
    
    for length in range (2, n+1) :
        for end in range (length, n+1) :
            start = end-(length-1)
            if (length % 2) == 0 :
                dp[start][end] = max(dp[start][end-1], dp[start+1][end])
                print("even")
                print("start, end : ", start, end)
            else :
                dp[start][end] = max(dp[start][end-1] + dp[end][end], dp[start+1][end] + dp[start][end-(length-1)])
                print("odd")
                print("start, end : ", start, end)
    for i in range(n+1) :
        print(dp[i])
    print(dp[1][n])