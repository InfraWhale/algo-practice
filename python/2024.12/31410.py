import sys # 8% 틀렸습니다.

n = int(sys.stdin.readline())
arr = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]

arr = sorted(arr, key=lambda x: x[0])
# print(arr)

ret_1 = 0
minus_1 = 0
for i in range (0, n) :
    temp_1 = (arr[n-1][0] - arr[i][0]) + arr[i][1]
    ret_1 += temp_1
    minus_1 = max(minus_1, temp_1)
ret_1 -= minus_1

ret_2 = 0
minus_2 = 0
for i in range (n-1, -1, -1) :
    temp_2 = (arr[i][0] - arr[0][0]) + arr[i][1]
    ret_2 += temp_2
    minus_2 = max(minus_2, temp_2)
ret_2 -= minus_2

print(min(ret_1, ret_2))