import sys # 8% 틀렸습니다. -> 맞았습니다

n = int(sys.stdin.readline())
arr = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]

arr = sorted(arr, key=lambda x: x[0])
# print(arr)

# 왼쪽 -> 오른쪽
ret_1 = 0
minus_1 = 0
for i in range (0, n-1) :
    temp_1 = (arr[n-1][0] - arr[i][0]) + arr[i][1]
    ret_1 += temp_1
    minus_1 = max(minus_1, temp_1)

# 오른쪽에서 맨 마지막(n-1)번째가 빠지는 경우를 따로 생각한다.
ret_1 = min(ret_1-minus_1+arr[n-1][1], ret_1-(arr[n-1][0] - arr[n-2][0])*(n-1))

# 오른쪽 -> 왼쪽
ret_2 = 0
minus_2 = 0
for i in range (n-1, 0, -1) :
    temp_2 = (arr[i][0] - arr[0][0]) + arr[i][1]
    ret_2 += temp_2
    minus_2 = max(minus_2, temp_2)

# 왼쪽에서 맨 마지막(0)번째가 빠지는 경우를 따로 생각한다.
ret_2 = min(ret_2-minus_2+arr[0][1], ret_2-(arr[1][0] - arr[0][0])*(n-1))

print(min(ret_1, ret_2))