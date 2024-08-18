import sys
from collections import deque

#6% 시간초과

k = int(sys.stdin.readline())

def dfs(start, vertex) :
    stack = deque([start])
    dfs_visited = [-1] * (vertex + 1)
    dfs_flag = True
    
    while stack :
        now = stack.pop()
        visited_val = dfs_visited[now]
        for it in arr[now] :
            if dfs_visited[it] == -1 :
                stack.append(it)
                dfs_visited[it] = 1 - visited_val
            elif dfs_visited[it] != visited_val :
                continue
            else :
                dfs_flag = False
                break 
        if not dfs_flag :
            break
    return dfs_flag

for _ in range (k) :
    v, e = map(int, sys.stdin.readline().split())

    arr = [[] for _ in range (v+1)]

    for _ in range (e) :
        a, b = map(int, sys.stdin.readline().split())
        arr[a].append(b)
        arr[b].append(a)
        dfs_visited = [0]*(v+1)
        
    flag_now = dfs(1, v)
    if flag_now :
        print("YES")
    else :
        print("NO")
