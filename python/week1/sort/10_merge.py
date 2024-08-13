# 정렬 마친 두 배열을 병합하기

from typing import Sequence, MutableSequence

def merge_sorted_list(a : Sequence, b: Sequence, c: MutableSequence) -> None :
    
    pa, pb, pc = 0, 0, 0 # 각 배열의 커서
    na, nb, nc = len(a), len(b), len(c) # 각 배열의 원소 수
    
    while pa < na and pb < nb: # pa와 pb를 비교하여 작은 값을 pc에 저장
        if a[pa] <= b[pb]:
            c[pc] = a[pa] # b[pb]가 더 크므로 a[pa]가 담김
            pa += 1
        else:
            c[pc] = b[pb] # a[pa]가 더 크므로 b[pb]가 담김
            pb += 1
        pc += 1
        
    while pa < na: # a에 남은 원소를 c에 복사
        c[pc] = a[pa]
        pa += 1
        pc += 1
    
    while pb < nb: # b에 남은 원소를 c에 복사
        c[pc] = b[pb]
        pb += 1
        pc += 1
        
    # 위의 2개의 while문은 구조상 하나만 일어날 것임
    
if __name__ == '__main__':
    # 정렬이 끝난 배열들
    a = [2, 4, 6, 8, 11, 13]
    b = [1, 2, 3, 4, 9, 16, 21]
    c = [None] * (len(a) + len(b))
    print('정렬을 마친 두 배열의 병합을 수행.')
    
    merge_sorted_list(a, b, c) # 배열 a와 b를 병합하여 c에 저장
    
    print('배열 a와 b를 병합하여 배열 c에 저장')
    
    print(f'배열 a: {a}')
    print(f'배열 b: {b}')
    print(f'배열 c: {c}')
