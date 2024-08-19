import sys
import heapq
# 프림으로 구현
v, e = map(int, sys.stdin.readline().split())

edges = [[] for i in range (v+1)]
visited = [0] * (v+1)

def prim() :
    ret = 0
    min_heap =[]
    heapq.heappush(min_heap, (0, 1)) # 최소 스패닝 트리는 어디서 시작하든 상관없다. (애초에 전제가 모든 vertex를 다 돌아야 하는 거니깐.)
    
    while min_heap :
        cost, vertex = heapq.heappop(min_heap)
        
        if visited[vertex] : # 방문검사를 아래에서 하긴 했지만, 가중치 더 작은 edge에 의해 해당 vertex가 이미 선점되었을 수 있다. 즉 한번 더해준다.
            continue
        visited[vertex] = 1

        ret += cost
        
        for edge in edges[vertex] :
            if visited[edge[1]] == 1 :
                continue
            heapq.heappush(min_heap, edge) # 현재 만들어진 트리에서 갈 수 있는 경우의 수를 하나씩 더해나간다고 생각하자. 우리는 그중에서 가중치가 가장 작은 것들만 뽑을거다.
        
    return ret

for _ in range (e) :
    a, b, c = map(int, sys.stdin.readline().split())
    edges[a].append((c, b))
    edges[b].append((c, a))

print(prim())