import math

a, b, v = map(int, input().split())

print(math.ceil((v-a) / (a-b)) + 1)
# 달팽이는 마지막날을 제외하면 v-a의 거리를 a-b의 속도로 간다.
# 마지막날에 a만큼 가니 시간 + 1