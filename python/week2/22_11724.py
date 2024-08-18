import sys
from collections import deque
n, m = map(int, sys.stdin.readline().split())

arr = [[] for _ in range (n+1)]

for _ in range (m) :
    a, b = map(int, sys.stdin.readline().split())
    arr[a].append(b)
    arr[b].append(a)
    
dfs_visited = [0]*(n+1)

def dfs(start) :
    stack = deque([start])
    while stack :
        now = stack.pop()
        if dfs_visited[now] == 1 : 
            continue
        
        dfs_visited[now] = 1
        for it in arr[now] :
            stack.append(it)
    return
cnt = 0
for i in range (1, n+1) :
    if dfs_visited[i] == 1 :
        continue
    dfs(i)
    cnt += 1
    
print(cnt)