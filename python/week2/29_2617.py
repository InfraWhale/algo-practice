import sys
sys.setrecursionlimit(10**6)

n, m = map(int, sys.stdin.readline().split())
visited = []
ret = 0

arr_forward = [[] for _ in range (n+1)]
arr_backward = [[] for _ in range (n+1)]

for _ in range (m) :
    a, b = map(int, sys.stdin.readline().split())
    arr_forward[a].append(b)
    arr_backward[b].append(a)

def dfs(start, arr) :
    sum = 0
    visited[start] = 1
    
    for go in arr[start] :
        if visited[go] : # 방문했으면
            continue
        sum += 1
        sum += dfs(go, arr)
    return sum

for i in range (1, n+1) :
    visited = [0]*(n+1)
    cnt = dfs(i, arr_forward) 
    if cnt >= (n//2) + 1 :
        ret += 1
        continue
    
    visited = [0]*(n+1)
    cnt = dfs(i, arr_backward)
    if cnt >= (n//2) + 1 :
        ret += 1
    
print(ret)
