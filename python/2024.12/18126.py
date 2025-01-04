import sys
sys.setrecursionlimit(10**6)

n = int(sys.stdin.readline())
arr = [[0 for _ in range(n+1)] for _ in range(n+1)]
visited = [0 for _ in range(n+1)]

for _ in range (n-1) :
    a, b, c = map(int, sys.stdin.readline().split())
    arr[a][b] = c
    arr[b][a] = c

ret = 0

def dfs (now, dist) :
    global ret
    
    for next in range(1, n+1) :
        if now == next or arr[now][next] == 0 or visited[next] == 1 :
            continue
        dist += arr[now][next]
        visited[next] = 1
        ret = max(ret, dist)
        dfs (next, dist)
        dist -= arr[now][next]
        visited[next] = 0
    return

visited[1] = 1
dfs(1, 0)

print(ret)
