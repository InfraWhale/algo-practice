##하노이 정답

# 메모리초과 -> 최대범위가 100 : 즉 재귀 100번 탈 수도 있는거. 2의 100승 -1번 호출될수도 있음
# 그림 그려보면 호출 횟수는 2의 n승 -1 나옴
# 횟수는 그냥 계산해서 프린트 해준다.

import sys

n = int(sys.stdin.readline())

print (2**n - 1)

def move (no, start, end) :
    if no > 1:
        move(no - 1, start, 6 - start - end)
    
    print(start, end)
    
    if no > 1:
        move(no - 1, 6 - start - end , end)
    return

if(n <= 20) :
    move(n, 1, 3)