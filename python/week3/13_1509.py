import sys

str = sys.stdin.readline().strip()
n = len(str)

dp = [[0 for x in range(n)] for y in range(n)]

for i in range(0, n) :
    dp[i][i] = 1 
    if i == n-1 : # i = 0일땐 dp[0][1]이 팰린드롬일 가능성이 있으므로 탐색해야한다.
        continue
    start = i-1
    end = i+1
    while (start >= 0 and end < n) :
        if str[start] == str[end] :
            dp[start][end] = 1
            start -= 1
            end += 1
        else :
            break
    
    if str[i] == str[i+1] :
        dp[i][i+1] = 1 # 해당 조건 추가
        start = i-1
        end = i+2
        while (start >= 0 and end < n) :
            if str[start] == str[end] :
                dp[start][end] = 1
                start -= 1
                end += 1
            else :
                break
            
INF = float('Inf')
dp_str = [INF] * (n+1)
dp_str[0] = 0

for target in range (1, n+1) :
    for i in range(1, target+1) :
        # 취중 코딩이라 아리쏭함. 16500 개념 재활용
        if dp_str[target - i] != INF and dp[target - i][target-1]: # dp[0][0]
            dp_str[target] = min(dp_str[target], dp_str[target - i] + 1)
            
print(dp_str[n])
