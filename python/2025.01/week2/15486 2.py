import sys # dp로 풀어야 함 (답 봤음)

n = int(sys.stdin.readline())

arr = [(0, 0)]
dp = [0 for _ in range (n+4)]

for start in range (1, n + 1) :
    days, cost = map(int, sys.stdin.readline().split())
    arr.append((days, cost))
    
for today in range(1, n+1) :
    dp[today] = max(dp[today], dp[today-1])
    days, cost = arr[today]
    if today + days - 1 <= n :
        # 처음엔 today + days가 아니라 today + days - 1로 하였음.
        # 이미 상담이 잡힌 날에 상담을 한 번 더 하게 되는 케이스가 발생
        # today + days로 변경하여 해결
        dp[today + days] = max(dp[today + days], dp[today] + cost)
        
print(max(dp))
    