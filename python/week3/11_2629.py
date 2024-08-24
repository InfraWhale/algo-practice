import sys

n = int(sys.stdin.readline()) # 추의 갯수

pounds = list(map(int, sys.stdin.readline().split()))

m = int(sys.stdin.readline()) # 구슬의 갯수

orbs = list(map(int, sys.stdin.readline().split()))

sum_pound = sum(pounds)

dp = [0] * ((sum_pound*2) + 1)
dp[sum_pound] = 1

for pound in pounds :
    for target_weight in range (sum_pound*2, -1, -1) :
        if target_weight - pound >= 0 and dp[target_weight - pound] != 0 : # 오른쪽에 올릴 때
            dp[target_weight] = 1
    for target_weight in range (0, (sum_pound*2) + 1) :
        if target_weight + pound <= sum_pound*2 and dp[target_weight + pound] != 0 : # 왼쪽에 올릴 때 (구슬을 놓는 곳)
            dp[target_weight] = 1
            
#print(dp)

for orb in orbs :
    if orb > sum_pound : # 구슬이 추 전체보다 무거울 수 있으므로
        print("N", end=" ")
    elif dp[orb + sum_pound] == 1 :
        print("Y", end=" ")
    else : 
        print("N", end=" ")