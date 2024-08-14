# 정렬 3

import sys

n = int(sys.stdin.readline())
arr = [0]*10001
for i in range(n) :
    temp = int(sys.stdin.readline())
    arr[temp] += 1

for i in range(len(arr)) :
    val = arr[i]
    if val == 0 :
        continue
    else :
        for j in range (val) :
            print(i)