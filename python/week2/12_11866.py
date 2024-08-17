import sys
from collections import deque

# 이게 되네

n, k = map(int, sys.stdin.readline().split())

que = deque([i for i in range(1, n+1)])
cnt = 0
list = []

while (len(que) > 0) :
    for _ in range (k-1):
        que.append(que.popleft())
    list.append(que.popleft())

print('<' + ', '.join(map(str, list)) + '>')