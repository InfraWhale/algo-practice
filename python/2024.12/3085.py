import sys #시간복잡도 개선.

n = int(sys.stdin.readline())

arr = [list(sys.stdin.readline().strip()) for _ in range(n)]

def maxCandyVertical(y, x) :
    max_cnt = 1
    cnt = 1
    for i in range(n-1) :
        if arr[y][i] == arr[y][i+1] :
            cnt += 1
        else :
            cnt = 1
        max_cnt = max(cnt, max_cnt)
    for i in range(x, x+2) :
        cnt = 1
        for j in range(n-1) :
            if arr[j][i] == arr[j+1][i] :
                cnt += 1
            else :
                cnt = 1
            max_cnt = max(cnt, max_cnt)
    return max_cnt

def maxCandyHorizontal(y, x) :
    max_cnt = 1
    cnt = 1
    for i in range(n-1) :
        if arr[i][x] == arr[i+1][x] :
            cnt += 1
        else :
            cnt = 1
        max_cnt = max(cnt, max_cnt)
    for i in range(y, y+2) :
        cnt = 1
        for j in range(n-1) :
            if arr[i][j] == arr[i][j+1] :
                cnt += 1
            else :
                cnt = 1
            max_cnt = max(cnt, max_cnt)
    return max_cnt

def maxCandy() :
    max_cnt = 1
    for i in range(n):
        # 가로 확인
        cnt = 1
        for j in range(1, n):
            if arr[i][j] == arr[i][j - 1]:
                cnt += 1
            else:
                cnt = 1
            max_cnt = max(cnt, max_cnt)
        # 세로 확인
        cnt = 1
        for j in range(1, n):
            if arr[j][i] == arr[j - 1][i]:
                cnt += 1
            else:
                cnt = 1
            max_cnt = max(cnt, max_cnt)

    return max_cnt

ret = 1

for i in range (n) :
    for j in range(n) :
        if j+1 < n and arr[i][j] != arr[i][j+1] :
            arr[i][j], arr[i][j+1] = arr[i][j+1], arr[i][j]
            ret = max(ret, maxCandyVertical(i, j))
            arr[i][j], arr[i][j+1] = arr[i][j+1], arr[i][j]
        if i+1 < n and arr[i][j] != arr[i+1][j] :
            arr[i][j], arr[i+1][j] = arr[i+1][j], arr[i][j]
            ret = max(ret, maxCandyHorizontal(i, j))
            arr[i][j], arr[i+1][j] = arr[i+1][j], arr[i][j]

ret = max(ret, maxCandy())

print(ret)