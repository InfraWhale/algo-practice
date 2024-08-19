import sys
from collections import deque
# 18% 틀렸습니다.
n, m, k, x = map(int, sys.stdin.readline().split())
arr = [[] for _ in range (n+1)]
for _ in range (m) :
    a, b = map(int, sys.stdin.readline().split())
    arr[a].append(b) # 단방향이다.
visited = [0]*(n+1)
ret_arr = []

# print(arr)
# print(visited)

def bfs(start) :
    que = deque([start])
    visited[start] = 1
    while que :
        now = que.popleft()
        
        for go in arr[now] :
            
            if visited[go] != 0:
                continue
            if visited[now] == k :
                ret_arr.append(go)
                #continue -> 이거 제거해준 이후 해결.
                #visited 안된 값들도 처리를 해줘야 했던거 같음.
            visited[go] = visited[now] + 1
            que.append(go)
    return

bfs(x)

if ret_arr :
    ret_arr.sort()
    for ret in ret_arr :
        print(ret)
else :
    print(-1)