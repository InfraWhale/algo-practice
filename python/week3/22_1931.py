import sys

n = int(sys.stdin.readline())

arr = [tuple(map(int, sys.stdin.readline().split())) for _ in range (n)]

arr.sort(key = lambda x: (x[1], x[0])) # 시작하자마자 끝나는 경우도 있으므로 첫번째 요소도 정렬하여야 함

#print(arr)

start, end = arr[0]
count = 1

for i in range (1, n) :
    temp_start, temp_end = arr[i]
    if temp_start >= end :
        count += 1
        start, end = temp_start, temp_end
    
print(count)