import sys
# 답이 생각 안나서 풀이를 봄
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

dp = [-1] * (max(arr) + 1)

for num in arr :
    for i in range (1, num) :
        if dp[i] != -1 and max_val[i] < num :
            dp[i] += 1
            max_val[i] = num
    if dp[num] == -1 :
        dp[num] = 1
        max_val[num] = num
        
print(max(dp))