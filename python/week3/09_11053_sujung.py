import sys
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
# 답이 생각 안나서 풀이를 봄
#해당 풀이 참고
# https://thingjin.tistory.com/entry/%EB%B0%B1%EC%A4%80-11053%EB%B2%88-%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4-%ED%8C%8C%EC%9D%B4%EC%8D%AC

length = len(arr)

dp = [1] * (length) # dp[i] # arr[i]를 마지막으로 가지는 부분행렬의 길이

for i in range(1, length) : # 배열 모든 요소

    for j in range(i) : # 0 ~ i-1
        if arr[i] > arr[j] :
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))