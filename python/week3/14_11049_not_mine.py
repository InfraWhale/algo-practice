import sys

# 다음 글 참고
#https://e-juhee.tistory.com/entry/python-%EB%B0%B1%EC%A4%80-11049-%ED%96%89%EB%A0%AC-%EA%B3%B1%EC%85%88-%EC%88%9C%EC%84%9C-DP
#pypy 안쓰면 시간초과

N = int(input())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

dp = [[0]*(N) for _ in range(N)] # 행렬의 번호를 저장

for term in range(1, N): # term : 계산 행렬의 간격
    for start in range(N):  # 첫행렬 : start, 끝행렬: start+term
        if start + term == N:  # 범위를 벗어나면 무시
            break

        dp[start][start+term] = int(1e9)  # 지금 계산할 첫행렬과 끝행렬

        for t in range(start, start+term):
            dp[start][start+term] = min(dp[start][start+term],
                                        # 👇 1 + 2 + 3
                                        dp[start][t]+dp[t+1][start+term] + arr[start][0] * arr[t][1] * arr[start+term][1]) # dp[start][t] 가 start 번째와 t번째의 곱이니, 중간엔 t번째 행렬의 열이 들어가는것이 맞다.

print(dp[0][N-1])
