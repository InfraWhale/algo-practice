import sys
from collections import deque
# 19% 틀렸습니다
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

arr_out = [[] for _ in range (n+1)]
arr_in = [0]*(n+1)

arr_max_cost = [0]*(n+1)
arr_max_cost_road = [0]*(n+1)

for _ in range (m) :
    a, b, c = map(int, sys.stdin.readline().split())
    arr_out[a].append((b, c))
    arr_in[b] += 1
    
start, end = map(int, sys.stdin.readline().split())

def topology_sort() :
    que = deque()
    que.append(start)
    
    while que :
        now_idx = que.popleft()
                
        for next in arr_out[now_idx] :
            next_idx, next_cost = next
            
            if next_cost + arr_max_cost[now_idx] > arr_max_cost[next_idx] :
                arr_max_cost[next_idx] = next_cost + arr_max_cost[now_idx]
                arr_max_cost_road[next_idx] = arr_max_cost_road[now_idx] + 1 # 단순히 count 해주면 안된다. 길이 중복될 수 있으므로
            
            elif next_cost+ arr_max_cost[now_idx] == arr_max_cost[next_idx] :
                arr_max_cost_road[next_idx] += (arr_max_cost_road[now_idx] + 1)
                
            # print("now_idx, next_idx : ", now_idx, next_idx)
            # print("arr_max_cost : ", arr_max_cost)
            # print("arr_max_cost_road : ", arr_max_cost_road)
            
            arr_in[next_idx] -= 1
            if arr_in[next_idx] == 0 :
                que.append(next_idx)
    return

topology_sort()

print(arr_max_cost[end])
print(arr_max_cost_road[end])