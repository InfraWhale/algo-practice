import sys
n = int(sys.stdin.readline())

arr_result = [0]*(n+4)

arr_result[0] = 1
arr_result[1] = 2

for i in range (2, n) :
    arr_result[i] = ((arr_result[i-2]%15746) + (arr_result[i-1]%15746)) % 15746

print(arr_result[n-1])