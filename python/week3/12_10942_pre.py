import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

# 12% 틀렸습니다.

dp = [0] * (n*2)

for i in range(0, n) :  # 1 ~ n: 시작점 0, 종료점 i
    mid = i // 2
    
    flag = True
    
    for j in range(0, mid + 1) : 
        if arr[j] != arr[i-j] :
            flag = False
    
    if flag :
        if n % 2 == 1 : # 수열 갯수가 홀수
            dp[i] = dp[2*(n-1)-i] = 1
        else : # 수열 갯수가 짝수
            dp[i] = dp[(2*n)-1-i] = 1
        
#print(dp)

m = int(sys.stdin.readline())
for _ in range (m) :
    a, b = map(int, sys.stdin.readline().split())
    start = a-1
    end = b-1
    
    if start == end or dp[start+end] == 1:
        print(1)
    else :
        print(0)