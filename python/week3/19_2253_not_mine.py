# https://xkdls19.tistory.com/308
# https://magentino.tistory.com/295 (틀렸습니다 나온다. 참고용.)
N,M = map(int,input().split())
trap = set(int(input()) for _ in range(M))

inf = float('inf')
 
# dp[v][x] x번째 위치에 갈 때 속도 v로 갈 경우 최솟값
dp = [[inf]*(N+1) for _ in range(150)] # 가속도가 1인 채로 유지해서 갈 경우 k(k-1)/2 > 10000인 k
dp[0][1] = 0 #dp엔 점프 수가 저장
if 2 not in trap:
    dp[1][2] = 1
 
for x in range(2,N): # x에
    for v in range(150): # 속도 v로 위치한 말이
        for nv in (v-1,v,v+1): # nv 속도로 -> 경우의 수 3개
            nx = x + nv # nx에 이동하는 경우
            if nx <= N and 1<=nv<150 and nx not in trap: # 돌다리 범위 / 1칸 이상 / 작은 돌멩이 x
                dp[nv][nx] = min(dp[nv][nx],dp[v][x]+1)
                
answer = min(dp[i][-1] for i in range(150))
print(answer if answer != inf else -1)

