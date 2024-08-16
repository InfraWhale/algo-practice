import sys
# 72% 틀렸습니다.
n, k = map(int, sys.stdin.readline().split())
s = sys.stdin.readline().strip()
stack = []
cnt = k
for i in range (n) :
    while stack and cnt > 0:
        if stack[-1] < s[i] :
            stack.pop()
            cnt -= 1
        else :
            break
    if len(stack) < n-k : # 해당 조건 줘서 해결
        stack.append(s[i])
ret = ''.join(stack)
print(ret)