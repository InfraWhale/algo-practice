import sys
t = int(sys.stdin.readline())
k = int(sys.stdin.readline())
# 방식은 생각났는데 구현법이 안떠올라... 답보고 품
arr_coin = []

arr_sum = [0] * (t+1)
arr_sum[0] = 1 # 1가지가 있음

for _ in range (k) :
    coin_val, coin_qty = map(int, sys.stdin.readline().split())
    arr_coin.append((coin_val, coin_qty))

#arr_coin.sort(key=lambda x: (x[0]))

for coin_val, coin_qty in arr_coin :
    for money in range(t, 0, -1) : # 내려가면서 탐색 (t ~> 1) : 내려가면서 탐색해야, 이전에 탐색한 결과가 나중 결과에 영향을 미치지 않음.
        for cq in range(1, coin_qty + 1) : # 동전갯수 (1 ~> 최대동전갯수)
            if money - coin_val * cq >= 0 and arr_sum[money - coin_val * cq] > 0: #money : 만들어야 하는 돈, money - coin_val * cq : 기존에 가지고 있는 조합
                arr_sum[money] += arr_sum[money - coin_val * cq]

print(arr_sum[t])
