import sys # 1% 틀렸습니다.
from collections import deque

t = int(sys.stdin.readline())
ret_arr = []
def choose() :
    length = len(arr)
    if length >= 4 :
        if arr[0] + arr[length-2] > arr[1] + arr[length-1] :
            return True
        elif arr[0] + arr[length-2] < arr[1] + arr[length-1] :
            return False
        else :
            if arr[0] > arr[length-1] :
                return True
            else :
                return False
    elif length > 1 :
        if arr[0] > arr[length-1] :
            return True
        else :
            return False
    else :
        return True

for _ in range(t) :
    n = int(sys.stdin.readline())
    arr = deque(list(map(int, sys.stdin.readline().split())))
    ret = 0

    turn = True
    while arr :
        score = 0
        if choose() :
            score += arr[0]
            arr.popleft()
        else :
            score += arr[-1]
            arr.pop()
        if turn :
            ret += score
            turn = False
        else :
            turn = True
    ret_arr.append(ret)

for ret in ret_arr :
    print(ret)