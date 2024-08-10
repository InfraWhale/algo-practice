##하노이 ... 모르겠다.

import sys

n = int(sys.stdin.readline())
arr = [[0], [0], [0]]
arr[0] = [sys.stdin.readline().strip() for i in range(n, 0, -1)]

# 원판 갯수가 짝수면
if(n%2 == 0) :
    #홀수 원반은 오른쪽 이동
    odd_cnt = 1
    #짝수 원반은 왼쪽 이동
    even_cnt = -1
# 원판 갯수가 홀수면
else :
    #홀수 원반은 오른쪽 이동
    odd_cnt = -1
    #짝수 원반은 왼쪽 이동
    even_cnt = 1

who_move = 1 # 현재 움직이는 원판

def rec():
    # arr[2]의 길이가 n이면 종료 넣기
    
    for i in range(3) :
        if arr[i][-1] == who_move : # top이 현재 움직일 순번인 경우
            if who_move%2 == 0 : # 현재 움직이는 원판이 짝수
                if len(arr[(i+even_cnt)%3]) == 0 or :
                    arr[(i+even_cnt)%3].push()
            else : # 현재 움직이는 원판이 홀수
                arr[(i+odd_cnt)%3].push()
            arr[i].pop()
            who_move = who_move + 1
            rec()
    return

rec(0, 0, "")

#print(dic)
print(len(dic))