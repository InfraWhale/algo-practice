import sys # 3% 틀렸습니다.
from collections import deque

t = int(sys.stdin.readline())

def get_dist(start, end) :
    return abs(start[0]-end[0]) + abs(start[1]-end[1])

for _ in range(t) :
    n = int(sys.stdin.readline())
    arr = []
    
    visited = [0 for _ in range(n+2)]
    for i in range(n+2) :
        x, y = map(int, sys.stdin.readline().split())
        arr.append((x, y))
    
    start = arr[0]
    end = arr[-1]
    queue = deque([start])
    
    visited[0] = 1
    
    happy = False

    while queue :
        now_x, now_y = queue.popleft()
        
        if get_dist((now_x, now_y), end) <= 1000 :
            happy = True
            break
    
        for i in range(1, n+2) :
            if visited[i] == 0 :
                if get_dist((now_x, now_y), arr[i]) <= 1000 :
                    queue.append(arr[i])
                    visited[i] = 1

    print ("happy" if happy else "sad")