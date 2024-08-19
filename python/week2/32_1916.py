import sys
import heapq
# 다익스트라 사용 
# 17% 시간초과 -> 아래 해결사항 추가하여 해결
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

arr = [[] for _ in range (n+1)]
for _ in range (m) :
    a, b, c = map(int, sys.stdin.readline().split())
    arr[a].append((c, b))

st, ed = map(int, sys.stdin.readline().split())

min_cost = [float('Inf')]*(n+1)

def bfs(fm) :
    heap = [(0, fm)] # 가중치(최소힙의 기준으로 잡아주려고) , 탐색하는 노드의 인덱스
    min_cost[fm] = 0
    while heap :
        now_cost, now_idx = heapq.heappop(heap)
        
        # 이거 추가해줌 (최단경로 아닐 경우 무시)
        if now_cost > min_cost[now_idx] :
            continue
        
        for go in arr[now_idx] :
            go_cost, go_idx = go
            if min_cost[go_idx] > min_cost[now_idx] + go_cost : # 최단거리 갱신이 일어날 경우 우선순위 큐에 추가
                min_cost[go_idx] = min_cost[now_idx] + go_cost
                heapq.heappush(heap, go)
    return

bfs(st)
print(min_cost[ed])