import sys
from collections import deque
# 메모리 초과 16% -> 96% -> 정답
n, k = map(int, sys.stdin.readline().split())
arr = []
for i in range (n) :
    arr.append(int(sys.stdin.readline()))
    
arr = list(set(arr))

for i in arr : # 동전 1개인 경우 테스트 케이스
    if i == k :
        print(1)
        exit()

dic = {}

def bfs() :
    coin = 1
    que = deque(arr)
    while que :
        coin += 1
                
        for _ in range(len(que)) :
            
            now = que.popleft()
            for it in arr :
                new = now + it
                
                if new in dic : # 중복 발생시 건너뛰어서 메모리초과 해결
                    continue
                
                if new == k :
                    print(coin)
                    exit()
                elif new < k :
                    que.append(new)
                    dic[new] = 1
    return

bfs()
print(-1)