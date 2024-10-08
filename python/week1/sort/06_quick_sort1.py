# 퀵 정렬 구현

from typing import MutableSequence

def qsort(a :MutableSequence, left: int, right: int) -> None :
    
    n = len(a)
    
    pl = left # 왼쪽 커서
    pr = right # 오른쪽 커서
    x = a[(left + right)//2] # 피벗(가운데 원소)
    
    while pl <= pr:
        while a[pl] < x:
            pl += 1
        while a[pr] > x:
            pr -= 1
        if pl <= pr:
            a[pl], a[pr] = a[pr], a[pl]
            pl += 1
            pr -= 1
    
    if left < pr: qsort(a, left, pr)
    if pl < right: qsort(a, pl, right)

def quick_sort(a: MutableSequence) -> None:
    qsort(a, 0, len(a) -1)
    
if __name__ == '__main__':
    print('퀵 정렬 수행.')
    num = int(input('원소 수를 입력하세요.: '))
    x = [None] * num # 원소수 num인 배열 생성
    
    for i in range(num) :
        x[i] = int(input(f'x[i]: '))

quick_sort(x)

print('오름차순 정렬됨')
for i in range(num):
    print(f'x[{i}] = {x[i]}')
