# 셸 정렬 알고리즘 구현

from typing import MutableSequence

def shell_sort(a :MutableSequence) -> None :
    
    n = len(a)
    h = n // 2
    while h > 0:
        for i in range(h, n) :
            j = i - h
            tmp = a[i]
            # 아래처럼 코딩한 이유 : 홀수이면 하나 남으니깐 그거까지 교환해주려고
            
            while j >= 0 and a[j] > tmp:
                a[j + h] = a[j]
                j -= h
            a[j + h] = tmp
        h //= 2
    
if __name__ == '__main__':
    print('이진 삽입 정렬을 수행합니다.')
    num = int(input('원소 수를 입력하세요.: '))
    x = [None] * num # 원소수 num인 배열 생성
    
    for i in range(num) :
        x[i] = int(input(f'x[i]: '))

binary_insertion_sort(x)

print('오름차순 정렬됨')
for i in range(num):
    print(f'x[{i}] = {x[i]}')
