import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
arr_ret = [-1 for _ in range (n)]
stk = []

for i in range(n) :
    
    while stk and stk[-1][1] < arr[i]:
        now = stk.pop()
        arr_ret[now[0]] = arr[i]
    
    stk.append((i, arr[i]))

for elem in arr_ret:
    print(elem, end=' ')