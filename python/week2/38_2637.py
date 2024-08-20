import sys
from collections import deque

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

arr_out = [[] for _ in range (n+1)]
arr_in =[0]*(n+1)

arr_cnt = [0]*(n+1)
arr_cnt[n] = 1

for _ in range (m) :
    a, b, c = map(int, sys.stdin.readline().split())
    arr_out[a].append((b, c))
    arr_in[b] += 1
    
def topology_sort() :
    que = deque()
    que.append((n, 1))    
    while que :
        now_idx = que.popleft()[0]
        
        if arr_out[now_idx] :
            now_cnt = arr_cnt[now_idx]
            arr_cnt[now_idx] = 0
            
            for next in arr_out[now_idx] :
                next_idx, next_vol = next
                arr_cnt[next_idx] += next_vol*now_cnt
                arr_in[next_idx] -= 1
                if arr_in[next_idx] == 0 :
                    que.append(next)
    return

topology_sort()

for i in range(n+1) :
    if arr_cnt[i] != 0 :
        print(i, arr_cnt[i])