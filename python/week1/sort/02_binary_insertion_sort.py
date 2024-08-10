# 이진 삽입정렬 알고리즘 구현

from typing import MutableSequence

def binary_insertion_sort(a :MutableSequence) -> None :
    n = len(a)
    for i in range(1, n) :
        key = a[i]
        pl = 0 # 검색 범위의 맨 앞 원소 인덱스
        pr = i-1 # 검색 범위의 맨 끝 원소 인덱스
        
        while True:
            pc = (pl + pr) // 2 # 검색 범위의 가운데 원소 인덱스
            if a[pc] == key: # 검색 성공
                break
            elif a[pc] < key:
                pl = pc + 1 # 검색범위를 뒤쪽 절반으로 좁힘 -> 시작점을 뒤쪽으로 땡겨옴
            else:
                pr = pc - 1 # 검색범위를 앞쪽 절반으로 좁힘 -> 종료점을 앞쪽으로 크게 땡겨옴
            if pl > pr:
                break
            
        pd = pc + 1 if pl <= pr else pr + 1 # 삽입해야 할 위치의 인덱스
        
        # if pl <= pr :
        #     pd = pc + 1
        # else :
        #     pd = pr + 1 : 이거 말하는건가?
        
        # pd번째에 i번쨰 삽입하기
        for j in range(i, pd, -1):
            a[j] = a[j-1]
        a[pd] = key
        
        #단순삽입정렬은 각 요소별 한회차를 써서, 요소 앞에있는 다른 요소들과 하나씩 비교해가면서 제 위치를 찾아서 삽입
        #이진삽입정렬은 유사하지만, 앞 요소들 어디에 삽입되어야 하는지를 이진탐색을 써서 찾은 다음에 삽입 (어려우니 한번 더 볼것.)
        
        j = i # i번째 요소 정렬 시작 -> j를 조금씩 줄여갈거므로 따로 저장
    
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
