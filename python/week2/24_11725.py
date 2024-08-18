import sys
from collections import deque
n = int(sys.stdin.readline())

arr = [[] for _ in range (n+1)]

for _ in range (n-1) :
    a, b = map(int, sys.stdin.readline().split())
    arr[a].append(b)
    arr[b].append(a)
    
dfs_visited = [0]*(n+1)
parent = [0]*(n+1)

def dfs(start) :
    stack = deque([start])
    while stack :
        now = stack.pop()

        dfs_visited[now] = 1
        for it in arr[now] :
            if dfs_visited[it] == 1 : 
                continue
            parent[it] = now
            stack.append(it)
    return

#print("--------")

dfs(1)

for i in range (2, n+1) :
    print(parent[i])