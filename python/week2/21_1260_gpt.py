import sys
from collections import deque
# 틀렸습니다 5%
n, m, v = map(int, sys.stdin.readline().split())

arr = [[] for _ in range (n+1)]
visited = [0]*(n+1)

for _ in range (m) :
    a, b = map(int, sys.stdin.readline().split())
    arr[a].append(b)
    arr[b].append(a)
    
for i in range (n) :
    arr[i].sort()

arr_a = []
arr_b = []

def dfs(start) :
    dfs_visited = [0]*(n+1)
    stack = deque([start])
    while stack :
        now = stack.pop()
        if dfs_visited[now] == 1 : 
            continue
        
        arr_a.append(now)
        if len(arr_a) == n :
            break
        
        dfs_visited[now] = 1
        for it in reversed(arr[now]) :
            stack.append(it)
    return

def bfs(start) :
    bfs_visited = [0]*(n+1)
    que = deque([start])
    while que :
        now = que.popleft()
        if bfs_visited[now] == 1 : 
            continue
        
        arr_b.append(now)
        if len(arr_b) == n :
            break
        
        bfs_visited[now] = 1
        for it in arr[now] :
            que.append(it)
    return

dfs(v)
bfs(v)

print(arr_a)
print(arr_b)