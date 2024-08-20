import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())

arr_out = [[] for _ in range (n+1)]
arr_in =[0]*(n+1)

arr_ret = []

for _ in range (m) :
    a, b = map(int, sys.stdin.readline().split())
    arr_out[a].append(b)
    arr_in[b] += 1
    
def topology_sort() :
    que = deque()
    
    for i in range (1, n+1) :
        if arr_in[i] == 0:
            que.append(i)
    
    while que :
        now = que.popleft()
        
        arr_ret.append(now)
        
        for i in arr_out[now] :
            arr_in[i] -= 1
            if arr_in[i] == 0 :
                que.append(i)
    return

topology_sort()

print(*arr_ret)