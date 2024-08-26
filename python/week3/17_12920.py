import sys

n, m = map(int, sys.stdin.readline().split())

# 6% 시간초과 -> gpt 풀이 보고 개선
# 파이썬 12% 시간초과 -> pypy 맞았습니다.

dp = [-1] * (m+1)
dp[0] = 0

for _ in range(n):
    item_weight, item_value, item_qty = map(int,sys.stdin.readline().split())
    
    k = 1 # 1, 2, 4,... 이렇게 나누고 나머지를 취한다면 1부터 나누기 전 숫자까지 모든 조합을 다 만들 수 있다. 원리는 잘 모르겠으나.
    while k <= item_qty :
        for target in range(m, (k*item_weight)-1, -1) :
            if dp[target - k*item_weight] != -1:
                dp[target] = max(dp[target], dp[target - k*item_weight] + k*item_value)
        item_qty -= k
        k *= 2
        
    for target in range(m, (item_qty*item_weight)-1, -1) :
        if dp[target - item_qty*item_weight] != -1:
            dp[target] = max(dp[target], dp[target - item_qty*item_weight] + item_qty*item_value)

print(max(dp))