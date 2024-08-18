import sys
from collections import deque
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

arr = [[] for _ in range (n+1)]

for _ in range (m) :
    a, b = map(int, sys.stdin.readline().split())
    arr[a].append(b)
    arr[b].append(a)
    
dfs_visited = [0]*(n+1)

def dfs(start) :
    stack = deque([start])
    count = 0
    while stack :
        now = stack.pop()
        if dfs_visited[now] == 1 : 
            continue
        count += 1
        dfs_visited[now] = 1
        for it in arr[now] :
            stack.append(it)
    return count

print(dfs(1)-1)