import sys
from collections import deque

#19% 틀렸습니다.

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

arr = [[0]*(n+1) for i in range(n+1)]
visited = [[0]*(n+1) for i in range(n+1)]
move_que = deque()

for _ in range(k) :
    a, b = map(int, sys.stdin.readline().split())
    arr[a][b] = 1

l = int(sys.stdin.readline())

for _ in range(l) :
    c, d = sys.stdin.readline().split()
    move_que.append((c, d))

snake_que = deque()
present_pos = (1, 1)
snake_que.append(present_pos)
move_set = 0 # 0, 1, 2, 3
cnt = 0
prev_count = 0 # 이전 plan_count

def go(y, x) :
    if move_set == 0 :
        return (y, x+1)
    elif move_set == 1 :
        return (y+1, x)
    elif move_set == 2 :
        return (y, x-1)
    else :
        return (y-1, x)
    
while True :
    if move_que :
        plan = move_que.popleft()
        plan_count = int(plan[0])
        plan_change = plan[1]
    else :
        plan_count = n + prev_count
        
    for i in range(plan_count - prev_count) :
        cnt += 1
        next_pos = go(present_pos[0], present_pos[1])
        
        if(next_pos[0] <= 0 or next_pos[0] > n or next_pos[1] <= 0 or next_pos[1] > n or visited[next_pos[0]][next_pos[1]]) :
            print(cnt)
            exit()
        
        present_pos = next_pos
        snake_que.append(present_pos)
        visited[present_pos[0]][present_pos[1]] = 1
        
        if arr[present_pos[0]][present_pos[1]] == 0 :
            pop_pos = snake_que.popleft()
            visited[pop_pos[0]][pop_pos[1]] = 0
        else :
            arr[present_pos[0]][present_pos[1]] = 0 # 사과 먹었으면 치우기 -> 해결 후 정답
            
    prev_count = plan_count
    
    if plan_change == 'D' :
        move_set = (move_set + 1) % 4
    else :
        move_set = (move_set - 1) % 4