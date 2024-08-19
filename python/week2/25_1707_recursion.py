import sys
sys.setrecursionlimit(10**6)
#재귀로 다시

k = int(sys.stdin.readline())
visited = []

def dfs(start, color) :
    
    visited[start] = color
    
    for it in arr[start] :
        if visited[it] == -1 :
            if not dfs(it, 1-color) :
                return False
        elif visited[it] == color :
            return False
    return True

for _ in range (k) :
    v, e = map(int, sys.stdin.readline().split())

    arr = [[] for _ in range (v+1)]

    for _ in range (e) :
        a, b = map(int, sys.stdin.readline().split())
        arr[a].append(b)
        arr[b].append(a)
    
    visited = [-1]*(v+1) # 이거에 tab 써서 터진거였음...
    flag = True
    for i in range (1, v+1) :
        if visited[i] != -1 :
            continue
        if not dfs(i, 0) :
            flag = False
            break
        
    if flag :
        print("YES")
    else :
        print("NO")
