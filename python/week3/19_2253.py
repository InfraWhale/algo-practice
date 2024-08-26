import sys
from collections import deque

# 80% 틀렸습니다. -> 단순히 점프 수를 저장하는 것이 아니라, 얼마의 스피드로 통과했는지도 반영해야 할 것 같다.

INF = float('Inf')
n, m = map(int, sys.stdin.readline().split())
dp  = [INF for x in range(n+1)]
dp[2] = 1

for _ in range (m) :
    small = int(sys.stdin.readline())
    dp [small] = -1

que = deque([])
que.append((2, 1))

while que :
    now_pos, now_spd = que.popleft()
    
    for i in range (-1, 2) :
        next_spd = now_spd + i
        next_pos = now_pos + next_spd
        next_jump = dp[now_pos] + 1
        
        if next_spd <= 0 or next_pos > n or dp[next_pos] == -1 or dp[next_pos] <= next_jump:
            continue
        dp[next_pos] = next_jump
        que.append((next_pos, next_spd))
        
if dp[n] == INF :
    print(-1)
else :
    print(dp[n])