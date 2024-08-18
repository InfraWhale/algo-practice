import sys
sys.setrecursionlimit(10**6)
# 탐색을 모든 외부에서 한다면? (풀이 보고 한거)
# 이래야 200점 달성

n = int(sys.stdin.readline())
is_in = [0] + list(map(int, sys.stdin.readline().rstrip())) # 전부 달라붙어있는 숫자 리스트에 담기
visited = [0]*(n+1)
count = 0

def dfs(start) :
    sum = 0
    visited[start] = 1
    for go in arr[start] :
        if visited[go] : # 방문했으면
            continue
        if is_in[go] : # 실내면
            sum += 1
            continue
        sum += dfs(go)
    return sum

arr = [[] for _ in range (n+1)]

for _ in range (n-1) :
    a, b = map(int, sys.stdin.readline().split())
    arr[a].append(b)
    arr[b].append(a)
    
    if is_in[a] and is_in[b] : # 둘다 실내면 count 2
        count += 2
    
#print(is_in)
#print(arr)

for i in range (1, n+1) :
    if is_in[i] or visited[i]:
        continue
    ret = dfs(i)
    count += ret * (ret-1)
    
print(count)
