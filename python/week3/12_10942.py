import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

# 나중에 답 한번 보면 좋을거같다. -> 다른 풀이도 비슷한듯?

dp = [[0 for x in range(n)] for y in range(n)]

for i in range(0, n) :
    dp[i][i] = 1 
    if i == n-1 : # i = 0일땐 dp[0][1]이 팰린드롬일 가능성이 있으므로 탐색해야한다.
        continue
    start = i-1
    end = i+1
    while (start >= 0 and end < n) :
        if arr[start] == arr[end] :
            dp[start][end] = 1
            start -= 1
            end += 1
        else :
            break
    
    if arr[i] == arr[i+1] :
        dp[i][i+1] = 1 # 해당 조건 추가
        start = i-1
        end = i+2
        while (start >= 0 and end < n) :
            if arr[start] == arr[end] :
                dp[start][end] = 1
                start -= 1
                end += 1
            else :
                break
#print(dp)

m = int(sys.stdin.readline())
for _ in range (m) :
    a, b = map(int, sys.stdin.readline().split())
    fst = a-1
    snd = b-1
    
    if dp[fst][snd] == 1:
        print(1)
    else :
        print(0)