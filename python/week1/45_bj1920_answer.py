import sys
input = sys.stdin.readline

n, m = map(int, input().split())
n_arr = list(map(int, input().split()))
n_arr.sort()

def can_cut_with_height(h):
    return sum(max(0, tree - h) for tree in n_arr) # 최적화 더 될거같은데...

# 이분 탐색을 통해 최대 높이를 찾기
start, end = 0, n_arr[-1]
best_height = 0

while start <= end:
    mid = (start + end) // 2
    if can_cut_with_height(mid) >= m:
        best_height = mid  # 현재 높이에서 충분히 자를 수 있음
        start = mid + 1  # 더 높은 높이로 시도
    else:
        end = mid - 1  # 낮은 높이로 시도

print(best_height)

# can_cut_with_height 함수:

# 높이 h를 기준으로 자를 수 있는 나무의 총 길이를 계산합니다.
# 이분 탐색:

# start와 end는 높이의 범위를 설정합니다.
# mid는 현재 시험할 높이입니다.
# can_cut_with_height(mid)가 m보다 크거나 같으면, mid 높이에서 나무를 충분히 자를 수 있음을 의미하므로, 더 높은 높이를 시도해봅니다.
# 그렇지 않으면, 더 낮은 높이로 시도합니다.
# 이 코드는 이분 탐색을 올바르게 적용하여 높이 h를 찾고, 문제의 요구사항을 충족합니다.