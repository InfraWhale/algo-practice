import sys
import heapq

n = int(sys.stdin.readline())

arr_p = []

for _ in range(n) :
    p_start, p_end = map(int, sys.stdin.readline().split())
    if p_start > p_end :
        p_start, p_end = p_end, p_start
    arr_p.append((p_start, p_end))

d = int(sys.stdin.readline())

arr_p.sort(key=lambda x: x[1])

min_heap = []
max_cnt = 0

for people in arr_p :
    people_start, people_end = people
    line_start = people_end-d # line_end = peopel_end
    
    if people_start >= line_start :
        heapq.heappush(min_heap, people_start)
        
    while min_heap :
        min_val = min_heap[0] # 최소힙이면 첫번째에 최솟값 정렬
        
        if min_val < line_start : # 처음에 arr_p를 최댓값 기준으로 오름차순 정렬했다.
            # -> 사람의 종료점은 철로의 종료점보다 작은 것이 보장된다(철로의 종료점 = 가장 나중 사람 종료점)
            heapq.heappop(min_heap)
        else :
            break
            
    max_cnt = max(len(min_heap), max_cnt)

print(max_cnt)