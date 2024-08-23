import sys
n = int(sys.stdin.readline())
# 잘 이해는 안감...

arr_result = [0]*(n+4)

arr_result[1] = 1 # SK
arr_result[2] = 2 # CY
arr_result[3] = 1

for i in range (4, n+1) :
    arr_result[i] = min(arr_result[i-1], arr_result[i-3]) + 1 # min()을 왜하는거...?

if arr_result[n] % 2 == 0 :
    print("CY")
else :
    print("SK")