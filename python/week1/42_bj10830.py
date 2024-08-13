import sys
sys.setrecursionlimit(10**6)

# 모듈러 연산 덧셈을 잘 생각할 것

n, b = map(int,sys.stdin.readline().split())
arr = []
# for i in range (n) :
#     arr.append(list(map(int,sys.stdin.readline().split())))
# 처음 받을 때, 한 번 나눠주는 작업이 필요하다.
for i in range (n) :
    line = list(map(int, sys.stdin.readline().split()))
    modified_line = [j % 1000 for j in line]
    arr.append(modified_line)

cnt = 0

def matrix_square(a:list, b:list) :
    temp = [[0 for j in range(n)] for i in range(n)]
    for i in range (n) :
        for j in range (n) :
            sum = 0
            for k in range (n) :
                sum += a[i][k]*b[k][j] % 1000
            temp[i][j] = sum % 1000
    return temp

def go(array, b_cnt) :
    # global cnt
    # cnt += 1
    # print(cnt)
    
    #기저사례
    if b_cnt == 1 :
        return arr
    
    div_cnt = b_cnt//2
    ret = go(array, div_cnt)
    ret = matrix_square(ret, ret)
    
    #b_cnt가 홀수일때 남은 1개 처리해줘야 함
    if (b_cnt % 2) == 1 :
        ret = matrix_square(ret, arr)

    return ret

#print(matrix_square(arr, arr))
#print(go(arr, b))
new_arr = go(arr, b)

# 이차원 배열 출력
for i in range(n):
    for j in range(n):
        print(new_arr[i][j], end=' ')
    print()
        
# print(cnt)
