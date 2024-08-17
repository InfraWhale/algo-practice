import sys
n = int(input())
circles = []
for _ in range(n):
    x, r = map(int, sys.stdin.readline().split())
    circles.append(("L", x - r)) # 왼쪽 점 = 중심 - 반지름
    circles.append(("R", x + r)) # 오른쪽 점 = 중심 + 반지름
# 오른쪽 점 R이 왼쪽 점 L보다 앞으로 오도록 정렬
circles.sort(key=lambda x: (x[0]),  reverse=True)
circles.sort(key=lambda x: x[1])
stack = []
count = 1
for circle in circles:
    if circle[0] == "L":
        stack.append(circle)
        continue
    total_width = 0
    while stack:
        prev = stack.pop()
        if prev[0] == "L":
            width = circle[1] - prev[1]
            if total_width == width:
                count += 2
            else:
                count += 1
            # 원이 만들어졌으므로 stack에 원을 의미하는 C와 너비 추가
            stack.append(("C", width))
            break
        elif prev[0] == "C":
            total_width += prev[1]
print(count)

