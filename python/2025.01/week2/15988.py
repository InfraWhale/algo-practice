import sys # 메모리 초과 -> 83% 인덱스 에러
# n = 1일때 처리 -> 똑같음
# 안전하게 dp 배열 크기 늘려줌 -> 해결

t = int(sys.stdin.readline())

for _ in range (t) :
    n = int(sys.stdin.readline())
    dp = [0 for _ in range(n+4)]
    dp[0] = 1
    dp[1] = 1
    if n >= 2 :
        dp[2] = 2
    for i in range(3, n+1) :
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009
    # print(dp)
    print(dp[n])