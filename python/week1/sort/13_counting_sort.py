# 도수 정렬 알고리즘 구현하기

from typing import MutableSequence
    
def fsort(a: MutableSequence, max: int) -> None:

    n = len(a) # 정렬할 배열 a
    f = [0] * (max + 1) # 누적 도수 분포표 배열 f
    b = [0] * n # 작업용 배열 b

    for i in range(n):
        f[a[i]] += 1 # 1단계 -> 도수분포표를 만든다 (각 원소 몇개 있는지)
    for i in range(1, max + 1): 
        f[i] += f[i-1] # 2단계 -> 누적 도수 분포표를 만든다. (해당 지점에서 총합이 몇인지)
    for i in range(n-1, -1, -1): # 뒤에서부터 탐색한다. # 3단계
        f[a[i]] -= 1 # a[]의 값을 인덱스로 하는 누적합을 찾는다.
        #누적합의 값을 1 줄여서, b의 인덱스를 구한다.
        b[f[a[i]]] = a[i] #b[]의 해당 위치에 a[]의 값을 넣는다.
        #앞선 과정에서 누적합의 값이 하나 줄었으므로, a[]의 값이 같다 하더라도 중복으로 입력되지 않는다.
    for i in range(n):
        a[i] = b[i] # 4단계 -> 작업용 배열을 원래 배열에 복사한다.

def counting_sort(a : MutableSequence) -> None:
    fsort(a, max(a))

if __name__ == '__main__':
    print('도수 정렬 수행')
    num = int(input('원소 수를 입력하세요.: '))
    x = [None] * num # 원소수 num인 배열 생성
    
    for i in range(num) :
        while True:
            x[i] = int(input(f'x[i]: '))
            if x[i] >=0: break

    counting_sort(x)

print('오름차순 정렬됨')
for i in range(num):
    print(f'x[{i}] = {x[i]}')
