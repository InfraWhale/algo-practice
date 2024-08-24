import sys

n = int(sys.stdin.readline())

# 행렬 크기 배열
matrices = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]

# dp 배열 초기화
dp = [[float('inf')] * n for _ in range(n)]

# 단일 행렬의 경우 연산 횟수는 0
for i in range(n):
    dp[i][i] = 0

# dp 테이블 계산
for length in range(2, n + 1):  # 부분 문제의 길이 2 ~ n
    for i in range(n - length + 1): # ??? i번 연산한단 얘긴가?
        j = i + length - 1
        # i부터 j까지의 행렬 곱셈 최소 연산 횟수 계산
        for k in range(i, j):
            q = dp[i][k] + dp[k + 1][j] + matrices[i][0] * matrices[k][1] * matrices[j][1]
            if q < dp[i][j]:
                dp[i][j] = q

# 결과 출력
print(dp[0][n - 1])
