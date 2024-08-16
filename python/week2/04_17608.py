import sys

n = int(sys.stdin.readline())
stk = []
for _ in range(n) :
    stk.append(int(sys.stdin.readline()))

cnt = 0
max = 0
now = 0

for _ in range(n) :
    now = stk[-1]
    if now > max :
        cnt += 1
        max = now
    stk.pop()
    
print(cnt)