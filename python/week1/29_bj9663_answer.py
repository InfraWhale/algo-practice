# n퀸 정답
import sys
n = int(sys.stdin.readline())
m = 2*n-1

row = [0] * n # 행에 놓는거 체크
column = [0] * n # 열에 놓는거 체크
diagonal_a = [0] * m # 왼쪽 아래 ~ 오른쪽 위 대각선 (세어보면 2n-1개 나온다)
# diagonal_a : 그림 그려보면 한 줄의 모든 칸이 i + j가 같다.
# i+j 가 0인 칸, 1인 칸 ... (2n-1)-1 인 칸이 나오고 이를 이용해서 점거된 줄을 표시한다.
# 즉 인덱스는 (i + j) 로 구한다.
diagonal_b = [0] * m # 왼쪽 위 ~ 오른쪽 아래 대각선 (세어보면 2n-1개 나온다)
# diagonal_a : 그림 그려보면 한 줄의 모든 칸이 i - j가 같다.
# i+j 가 -(n-1) 인 칸, -(n-2)인 칸 ... (n-1) 인 칸이 나오고 이를 이용해서 점거된 줄을 표시한다.
# 단 배열 인덱스에 음수를 넣어줄 순 없으므로, 각각 (n-1)을 더해주면, 0인 칸, 1인 칸 ... (2n-1)-1인 칸이 된다.
# 즉 인덱스는 (i - j) + (n-1) 로 구한다.

arr = [[0 for j in range(n)] for i in range(n)]
visited = [[0 for j in range(n)] for i in range(n)]

def rec(i, cnt):  #i행에 하나 놓는다.
    
    for j in range(n) : # j열에 넣는 경우
        if column[j] or diagonal_a[i+j] or diagonal_b [i-j+(n-1)]: # 공격당하는 경우면 다음으로 넘김
            continue
        row[i] = j # i행 j열에 하나 놓는다.
        # 기저사례
        if i == (n-1) :
            cnt += 1
            return cnt
        column[j] = diagonal_a[i+j] = diagonal_b [i-j+(n-1)] = 1 # 해당 부분이 공격당함
        cnt = rec(i+1, cnt)
        column[j] = diagonal_a[i+j] = diagonal_b [i-j+(n-1)] = 0 # 해당 부분이 공격 풀림
    return cnt

print(rec(0, 0))