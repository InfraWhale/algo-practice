import sys
# 풀이 참고하여 해결
# https://wooono.tistory.com/605

n, m = map(int, sys.stdin.readline().split())

robo_map = [list(map(int,sys.stdin.readline().split())) for i in range(n)]

INF = float('Inf')
dp =  [[-INF for x in range(m)] for y in range(n)]
dp[0][0] = robo_map[0][0]

for i in range (1, m) :
    dp[0][i] = dp[0][i-1] + robo_map[0][i]
    
for i in range (1, n) :
    temp1 = [-INF]*m # 0 ~> m-1
    temp2 = [-INF]*m # m-1 ~> 0
    
    for j in range(m-1, -1, -1) :
        if j == m-1 :
            temp2[j] = dp[i-1][j] + robo_map[i][j]
        else :
            temp2[j] = max(temp2[j+1] + robo_map[i][j], dp[i-1][j] + robo_map[i][j])
    
    for j in range(0, m) :
        if j == 0 :
            temp1[j] = dp[i-1][j] + robo_map[i][j]
        else :
            temp1[j] = max(temp1[j-1] + robo_map[i][j], dp[i-1][j] + robo_map[i][j])

        dp[i][j] = max(temp1[j], temp2[j])
        
print(dp[n-1][m-1])