import sys
# 96% 틀렸습니다.
n, k = map(int, sys.stdin.readline().split())
arr = []
for i in range (n) :
    arr.append(int(sys.stdin.readline()))    
arr = list(set(arr))

INF = float('inf')
dp = [INF] * (k+1) # 해당 금액을 달성하기 위한 최소 동전 수를 저장해놓는다.
dp[0] = 0

for coin in arr :
    for amount in range(coin, k+1) :
        if dp[amount - coin] != INF : #현재 동전과 내가 가지고 있는 합의 조합으로 amount만큼의 금액을 만들 수 있을 경우
            dp[amount] = min(dp[amount], dp[amount - coin] + 1) # amount 만큼의 금액은 현재 가지고 있는 조합 + 1의 개수로 줄일 수도 있다. 단 결과가 그리 좋지 않으면 이전 것을 그대로 쓴다.
            
ret = dp[k]

if ret == INF :
    print(-1)
else :
    print(ret)