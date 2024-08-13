# 퀵 정렬 구현

from typing import MutableSequence

def sort3 (a : MutableSequence, idx1 : int, idx2 : int, idx3 : int):
    if a[idx2] < a[idx1] : 
        a[idx2], a[idx1] = a[idx1], a[idx2]
    if a[idx3] < a[idx2] : 
        a[idx3], a[idx2] = a[idx2], a[idx3]
    if a[idx2] < a[idx1] : 
        a[idx2], a[idx1] = a[idx1], a[idx2]  
    return idx2

# 교재에선 인덱스 9 미만이면 단순 삽입정렬 사용. 단 귀찮으니 생략함.

def qsort(a :MutableSequence, left: int, right: int) -> None :
        
    pl = left # 왼쪽 커서
    pr = right # 오른쪽 커서
    m = sort3(a, pl, (pl+pr)//2, pr)
    x = a[m]
    
    a[m], a[pr-1] = a[pr-1], a[m] # 중간 원소를 pr 직전 위치랑 바꾼다.
    
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
