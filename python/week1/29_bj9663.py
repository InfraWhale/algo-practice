# 시간복잡도 줄여야... ㅜㅜ

import sys

n = int(sys.stdin.readline())

arr = [[0 for j in range(n)] for i in range(n)]
visited = [[0 for j in range(n)] for i in range(n)]

def rec(y, x, depth, cnt):
    # 기저사례
    if depth == n :
        cnt += 1
        #print(arr)
        return cnt
    else :
        for i in range(y, n) : 
            for j in range(n) :
                if i == y and j < x :
                    continue
                if visited[i][j] > 0 :
                    continue

                arr[i][j] = 1
                for k in range(n) :
                    visited[k][j] += 1
                    visited[i][k] += 1
                    if i+k >= 0 and i+k < n and j+k >= 0 and j+k < n:
                        visited[i+k][j+k] += 1
                    if i-k >= 0 and i-k < n and j+k >= 0 and j+k < n:
                        visited[i-k][j+k] += 1
                    if i+k >= 0 and i+k < n and j-k >= 0 and j-k < n:
                        visited[i+k][j-k] += 1
                    if i-k >= 0 and i-k < n and j-k >= 0 and j-k < n:
                        visited[i-k][j-k] += 1
                visited[i][j] -= 1
                cnt = rec(i, j+1, depth + 1, cnt)
                arr[i][j] = 0
                for k in range(n) :
                    visited[k][j] -= 1
                    visited[i][k] -= 1
                    if i+k >= 0 and i+k < n and j+k >= 0 and j+k < n:
                        visited[i+k][j+k] -= 1
                    if i-k >= 0 and i-k < n and j+k >= 0 and j+k < n:
                        visited[i-k][j+k] -= 1
                    if i+k >= 0 and i+k < n and j-k >= 0 and j-k < n:
                        visited[i+k][j-k] -= 1
                    if i-k >= 0 and i-k < n and j-k >= 0 and j-k < n:
                        visited[i-k][j-k] -= 1
                visited[i][j] += 1
    return cnt

ret = rec(0, 0, 0, 0)
print(ret)