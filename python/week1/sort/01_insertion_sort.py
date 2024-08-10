# 단순 삽입정렬 알고리즘 구현

from typing import MutableSequence

def insertion_sort(a :MutableSequence) -> None :
    n = len(a)
    for i in range(1, n) :
        j = i # i번째 요소 정렬 시작 -> j를 조금씩 줄여갈거므로 따로 저장
        tmp = a[i] # i번째 요소 값 일시 저장
        while j > 0 and a[j - 1] > tmp : 
            # 현재 체크하는 요소의 값이 (i번째의 이전 요소) i번째의 값보다 크다면? -> 진행 
            # + 현재랑 현재 -1 의 요소를 비교하므로 i에 0이 들어가면 -> 배열에 -1이 들어감 -> 막아주자   
            a[j] = a[j - 1] # 현재 요소 위치에 이전 요소 값 넣는다.
            # + 앞 요소가 더 작으면 교환을 멈춘다. -> 앞 요소들이 모두 정렬이 완료되어있다고 가정하므로 가능한 것.
            j -= 1 # 이전 요소로 이동.
        a[j] = tmp # 루프가 끝나고, 이동한 이전 요소에 값 넣기 : 여기까지가 사실상 삽입
    # 요거를 1 ~ n-1까지 반복한다.
    
    
    
if __name__ == '__main__':
    print('단순 삽입 정렬을 수행합니다.')
    num = int(input('원소 수를 입력하세요.: '))
    x = [None] * num # 원소수 num인 배열 생성
    
    for i in range(num) :
        x[i] = int(input(f'x[i]: '))

insertion_sort(x)

print('오름차순 정렬됨')
for i in range(num):
    print(f'x[{i}] = {x[i]}')
