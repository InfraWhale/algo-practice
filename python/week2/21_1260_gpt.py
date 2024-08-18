import sys
from collections import deque

input = sys.stdin.readline

n, m, v = map(int, input().split())

# 인접 리스트 초기화
arr = [[] for _ in range(n+1)]

# 그래프 입력
for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)

# 각 정점에 대해 인접 리스트 정렬
for i in range(1, n+1):
    arr[i].sort()

def dfs(start):
    stack = [start]
    dfs_visited = [False] * (n+1)
    result = []
    
    while stack:
        now = stack.pop()
        if dfs_visited[now]:
            continue
        
        result.append(now)
        dfs_visited[now] = True
        
        # 인접 리스트를 역순으로 탐색
        for neighbor in reversed(arr[now]):
            if not dfs_visited[neighbor]:
                stack.append(neighbor)
                
    return result

def bfs(start):
    queue = deque([start])
    bfs_visited = [False] * (n+1)
    result = []
    
    while queue:
        now = queue.popleft()
        if bfs_visited[now]:
            continue
        
        result.append(now)
        bfs_visited[now] = True
        
        for neighbor in arr[now]:
            if not bfs_visited[neighbor]:
                queue.append(neighbor)
                
    return result

# 결과 출력
print(" ".join(map(str, dfs(v))))
print(" ".join(map(str, bfs(v))))
