import sys
n = int(sys.stdin.readline())
w = [list(map(int,sys.stdin.readline().split())) for i in range(n)]
picked = []
visited = [[0]*n for i in range(n)]
min_val = 987654321
origin = -1

def get_sum(a) :
    sum = 0
    for i in range (0, len(a)) :
        sum += w[a[i][0]][a[i][1]]
    return sum

def get_min(start, depth, ret) :
    if depth == n :
        ret = min(ret, get_sum(picked))
        # print("@", picked, ret)
        return ret
    
    for i in range (n) :
        if visited[i] == 1 or w[start][i] == 0 or (depth != n-1 and i == origin):
            continue
        
        picked.append( (start, i) ) # 튜플을 저장
        visited[i] = 1
        
        ret = get_min(i, depth + 1, ret)
        
        picked.pop()
        visited[i] = 0
    return ret

for i in range (n) :
    origin = i
    min_val = get_min(i, 0, min_val)
    # print(i, " : ", min_val)
print(min_val)