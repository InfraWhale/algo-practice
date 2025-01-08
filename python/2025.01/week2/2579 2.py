import sys # 시간초과 (for문 풀이)

n = int(sys.stdin.readline())

arr = [int(sys.stdin.readline()) for _ in range(n)]

if n == 1 :
    print(arr[0])
elif n == 2 :
    print(arr[0] + arr[1])
else :
    
    dp = [-1 for _ in range (n)]

    dp[0] = arr[0]
    dp[1] = arr[0] + arr[1]
    
    if n > 2:
        dp[2] = max(arr[0] + arr[2], arr[1] + arr[2])

    for i in range (3, n) :
        dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i])
        
    print(dp[n-1])

