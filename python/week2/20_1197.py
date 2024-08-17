import sys
# 메모리 초과
v, e = map(int, sys.stdin.readline().split())

arr = [[0]*v for _ in range (v)]
visited = [0]*v

for _ in range (e) :
    a, b, c = map(int, sys.stdin.readline().split())
    arr[a-1][b-1] = arr[b-1][a-1] =c

min_val = float('Inf')

def go(now, depth, cnt) : 
    
    global min_val
    
    if depth == v-1 :
        min_val = min(min_val, cnt)
        return
    
    for i in range (v) :
        if visited[i] == 1 or arr[now][i] == 0:
            continue
        
        visited[i] = 1
        cnt+=arr[now][i]
        go(i, depth+1, cnt)
        cnt-=arr[now][i]
        visited[i] = 0
    
    return

for i in range(v) :
    visited[i] = 1
    go(i, 0, 0)
    visited[i] = 0

print(min_val)