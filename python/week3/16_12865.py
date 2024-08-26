import sys

n, k = map(int, sys.stdin.readline().split())

items = []

for _ in range (n) :
    items.append(map(int,sys.stdin.readline().split()))

dp = [-1] * (k+1)
dp[0] = 0

for item in items :
    item_weight, item_value = item
    
    for target in range(k, item_weight-1, -1) :
        if dp[target - item_weight] != -1 :
            dp[target] = max(dp[target], dp[target - item_weight] + item_value)

print(dp)
#print(max(dp))
        

