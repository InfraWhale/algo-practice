import sys

n = int(sys.stdin.readline())

arr_fibo = [0]*(n+1)

arr_fibo[0] = 0
arr_fibo[1] = 1

if n == 1 :
    print(1)
    exit()

for i in range (2, n+1) :
    arr_fibo[i] = arr_fibo[i-1] + arr_fibo[i-2]

print(arr_fibo[n])