import sys
# 대충 생각하는 2805 문제 해결법
# 나무를 순서대로 정렬한다.
# 센터에 있는 나무 기준으로 잘랐을 때, 얻는 나무의 길이를 확인한다. + 최대값, 최소값, 그때의 나무 번호를 기록한다.
# 딱맞다면 끝
# 안맞다면 이분탐색하듯이 위나 아래로 보낸다.

# 최댓값, 최솟값 찾았다면, 최댓값 기준 조금씩 h를 올려본다. -> 가장 인접한 값일때를 출력한다.

# 이분 탐색 구현 오류:

# 현재 코드에서는 tree_calc 함수를 사용하여 높이 h를 정하고, 이 값을 기준으로 자른 나무의 양을 계산하고 있습니다. 하지만 이분 탐색의 범위가 잘못 설정되어 있습니다. 나무의 높이 h는 나무 배열의 값이 아니라, 자를 수 있는 임의의 높이일 수 있어야 합니다.
# find 함수의 로직 오류:

# find 함수에서 temp가 m과 같을 때 flag를 True로 설정하고 현재 인덱스를 반환합니다. 그러나 temp가 정확히 m이 아닌 경우에도 고려해야 합니다.
# temp가 m보다 작을 때 end를 mid-1로 설정하고, temp가 m보다 클 때 start를 mid+1로 설정하는데, 이분 탐색의 start와 end 범위 조정이 적절하지 않을 수 있습니다.
# 반례 및 예외 처리:

# 높은 정확도를 위해 반례를 확인할 필요가 있습니다. 특히 m이 tree_calc 결과에 딱 맞지 않는 경우에 대해 처리하는 부분에서 문제를 일으킬 수 있습니다.

n, m = map(int,sys.stdin.readline().split())
n_arr = list(map(int, sys.stdin.readline().split()))
flag = False
n_arr.sort()

def tree_calc(idx) :
    h = n_arr[idx]
    sum = 0
    for i in range(idx+1, n) :
        sum += (n_arr[i]-h)
    return sum

def find() :
    global flag
    start = 0
    end = n-1
    
    while True :
        mid = (start + end) // 2
        temp = tree_calc(mid)
        
        if temp == m :
            flag = True
            return mid
        elif temp < m :
            end = mid-1
        else :
            start = mid+1
        if start > end :
            if temp > m :
                return mid
            else :
                return mid - 1

tree_no = find()

if flag :
    print(n_arr[tree_no])
else :
    # 조금씩 잘라본다
    cnt = (n-1) - tree_no # tree_no 뒤에 있는 나무 갯수
    tree_now = n_arr[tree_no]
    tree_next = n_arr[tree_no+1]
    minus = n_arr[tree_no+1] - n_arr[tree_no] # 현재 나무와 다음 나무의 높이차
    volume = tree_calc(tree_no) # 현재 나무 얻은 양
    
    tree_print = tree_next-1
    
    for i in range (1, minus) :
        volume -= cnt
        if(volume < m) :
            tree_print = tree_now + (i-1)
            break
    print(tree_print)