import sys
# 답보고 작성
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
stack = []
ret = [0]*n

for i in range (n) :
    while stack and stack[-1][0] < arr[i] :
        stack.pop()
    if stack :
        ret[i] = stack[-1][1] + 1
    
    stack.append((arr[i], i))
for i in ret :
    print(ret[i], end=' ')