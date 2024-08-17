# 백준 2261
# 답 보고 품...
import sys

input = sys.stdin.readline

n = int(input())
arr = []

for _ in range(n):
    x, y = map(int, input().split())
    arr.append((x, y))
    
arr.sort()

# 영역에서 최소거리 구하기
def find_min_dist(start, end):
    min_dist = float('inf')
    for i in range(start, end): # 비교할 첫번째 점 인덱스
        for j in range(i+1, end) : # 비교할 두번째 점 인덱스
            dist = (arr[i][0] - arr[j][0])**2 + (arr[i][1] - arr[j][1])**2
            min_dist = min(min_dist, dist)
    return min_dist

def div_and_con(start, end):
    size = end - start
    if size < 3 :
        return find_min_dist(start, end)
    
    mid = (start + end) // 2
    
    left = div_and_con(start, mid)
    right = div_and_con(mid, end)
    
    min_dist = min(left, right)
    
    y_arr = []
    divide_x = arr[mid][0] # 가운데 기준 x좌표
    for i in range(start, end) :
        if (arr[i][0] - divide_x)**2 <= min_dist: # 분할 진행한 점의 x좌표 기준으로, 현재 최솟값 범위 탐색
            y_arr.append(arr[i]) # 해당하는 것은 넣는다.
    y_arr.sort(key=lambda x:x[1]) # y좌표 기준 오름차순 정렬

    for i in range(len(y_arr)): # 비교할 첫번째 점 인덱스
        now = y_arr[i]
        for j in range(i+1, len(y_arr)): # 비교할 두번째 점 인덱스
            compare = y_arr[j]
            if (compare[1] - now[1])**2 >= min_dist:
                break
            dist = (now[0] - compare[0])**2 + (now[1] - compare[1])**2
            min_dist = min(min_dist, dist)
    
    return min_dist 

print(div_and_con(0, n))