import sys # 1% 시간초과

n, m, q = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n+1)]
cost = [[0 for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m) :
    b, t, c = map(int, sys.stdin.readline().split())
    graph[b].append(t);
    cost[b][t] = c

ret = 0 
visited = []

def dfs(now, dest, sum_cost) :
    global ret
    
    if now == dest :
        ret = min(ret, sum_cost)
        return
    
    for nex in graph[now] :
        if visited[nex] == 1 :
            continue
        sum_cost += cost[now][nex]
        visited[nex] = 1
        dfs(nex, dest, sum_cost)
        sum_cost -= cost[now][nex]
        visited[nex] = 0
    return

for _ in range(q) :
    s, k, e = map(int, sys.stdin.readline().split())
    visited = [0 for _ in range(n+1)]
    visited[s] = 1
    visited[k] = 1
    ret = float('Inf')
    dfs(s, e, 0)
    
    if ret == float('Inf') :
        print("No")
    else :
        print(ret)