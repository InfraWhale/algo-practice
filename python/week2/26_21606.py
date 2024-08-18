import sys
sys.setrecursionlimit(10**6)
# 108점(60%)


n = int(sys.stdin.readline())
is_in = [0] + list(map(int, sys.stdin.readline().rstrip())) # 전부 달라붙어있는 숫자 리스트에 담기
visited = [0]*(n+1)
count = 0

def dfs(start) :
    global count
    for go in arr[start] :
        if visited[go] :
            continue
        if is_in[go] :
            count += 1
            continue
        visited[go] = 1
        dfs(go)
        visited[go] = 0
    return

arr = [[] for _ in range (n+1)]

for _ in range (n-1) :
    a, b = map(int, sys.stdin.readline().split())
    arr[a].append(b)
    arr[b].append(a)
    
#print(is_in)
#print(arr)

for i in range (1, n+1) :
    if not is_in[i] :
        continue
    visited[i] = 1
    dfs(i)
    
print(count*2)
