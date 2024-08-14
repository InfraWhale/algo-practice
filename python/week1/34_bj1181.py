# 정렬 4
import sys
from functools import cmp_to_key

def custom_compare(a, b):
    a_len = len(a)
    b_len = len(b)
    if a_len > b_len: # 쉬운 비교를 위해 a > b를 유지하는게 좋을 것 같다.
        return 1 # return 1:앞뒤를 바꾼다.(앞이 뒤보다 크다.)
    elif a_len == b_len:
        if a > b : return 1 # 사전순에서 수치가 앞이 뒤보다 더 크므로 둘을 바꿔준다.
        elif a == b : return 0 # return 0: 그대로 둔다.(양쪽이 같다.)
        else : return -1 # return -1: 그대로 둔다.(앞이 뒤보다 작다.)
    else:
        return -1

n = int(sys.stdin.readline())
arr = []
for i in range(n) :
    temp = sys.stdin.readline().strip()
    if temp not in arr:
        arr.append(temp)

arr.sort(key=cmp_to_key(custom_compare))

# print(arr)

for i in arr :
    print(i)