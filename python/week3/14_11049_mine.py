import sys
# 바로 틀렸습니다 나온 코드
n = int(sys.stdin.readline())

dp = [[(0, 0, 0) for x in range(n)] for y in range(n)]

for i in range(n) :
    a, b = map(int, sys.stdin.readline().split())
    dp[i][i] = (0, a, b) 
    
for j in range(1, n) :   
    for i in range(n-j) :
        temp = float('Inf')
        
        for k in range(1, j) :
            first_val, first_a , first_b = dp[i][i+(j-1)]
            second_val, second_a, second_b = dp[i+j][i+j]
            temp = min(first_val + second_val + first_a * second_a * second_b, temp)
        

        
        temp2 = first_val + first_a * second_a * second_b
        
        dp[i][i+j] = (min(temp1, temp2), first_a, second_b)
        
for i in range (n) :
    print(dp[i])

print(dp[0][n-1][0])