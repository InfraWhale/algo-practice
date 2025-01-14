import sys # 3% 틀렸습니다.

t = int(sys.stdin.readline())

def get_dist(start, end) :
    return abs(start[0]-end[0]) + abs(start[1]-end[1])

for _ in range(t) :
    n = int(sys.stdin.readline())
    arr = []
    visited = [0 for _ in range(n)]
    now_y, now_x = map(int, sys.stdin.readline().split())
    for i in range(n) :
        x, y = map(int, sys.stdin.readline().split())
        arr.append((x, y))
    dest_y, dest_x = map(int, sys.stdin.readline().split())
    
    find_end = False
    cant_find = False
    for _ in range(n) :
        if get_dist((now_x, now_y), (dest_x, dest_y)) <= 1000 :
            print("happy")
            find_end = True
            break
        
        temp_idx = -1
        temp_dist = 987654321
        for i in range(n) :
            if visited[i] == 1 :
                continue
            next_dist = get_dist((now_x, now_y), arr[i])
            if next_dist <=1000 and temp_dist > next_dist :
                temp_idx = i
                temp_x, temp_y = arr[i]
                temp_dist = next_dist
        # print("temp idx : ", temp_idx)
        if temp_idx == -1 :
            print("sad")
            cant_find = True
            break
        else :
            now_x, now_y = arr[temp_idx]
            visited[temp_idx] = 1
            
    if find_end or cant_find:
        continue
    elif get_dist((now_x, now_y), (dest_x, dest_y)) <= 1000 :
        print("happy")
    else :
        print("sad")