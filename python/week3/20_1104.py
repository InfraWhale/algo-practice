import sys

n, k = map(int, sys.stdin.readline().split())

arr = [int(sys.stdin.readline()) for i in range (n)]

count = 0

for i in range (n-1, -1, -1) :
    coin = arr[i]
    if coin > k :
        continue
    add, k = divmod(k , coin)
    count += add
    if k == 0 :
        break

print(count)