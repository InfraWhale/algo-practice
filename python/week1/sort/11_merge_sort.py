# 병합 정렬 알고리즘 구현하기

from typing import MutableSequence

def merge_sort(a : MutableSequence) -> None :
    
    def _merge_sort(a: MutableSequence, left: int, right: int) -> None:
    
        if left < right:
            center = (left + right) // 2
            
            _merge_sort(a, left, center) #배열 앞부분을 병합 정렬
            _merge_sort(a, center + 1, right) # 배열 뒷부분을 병합 정렬
            
            p = j = 0
            i = k = left
            
            while i <= center:
                buff[p] = a[i] # 작업용 배열의 0 위치부터 시작 : 입력받을곳
                # a[]의 분할된 위치의 시작부터 중앙까지 꺼내서 buff[]에 넣는다.
                p += 1 # p의 종료지점 : buff[]의 입력이 끝난 다음 지점
                i += 1 # i의 종료지점 : a[]의 center의 다음 지점
                                
            while i <= right and j < p: # a[]의 앞 절반이 담긴 buff[]와 a[]의 뒷 절반을 합친다.
                # 합쳐지는 위치는 a[] 전체를 마치 빈 배열인거 마냥 덮어씌운다.
                # 최악의 경우 buff[]의 내용물 전체가 a에 덮어씌워진다 하더라도, 원상복구 될 뿐이므로 
                # a의 데이터가 덮어씌워질 걱정은 할 필요 없다.
                if buff[j] <= a[i]:
                    a[k] = buff[j] # buff[]의 처음부터 시작하여, a[]의 분할된 배열의 시작지점부터 덮어씌운다
                    j += 1 # j : buff[]의 위치
                else :
                    a[k] = a[i] # a[]의 중간부터 시작하여, a[]의 분할된 배열의 시작지점부터 덮어씌운다
                    i += 1 # i : 뒷부분 a[]의 위치
                k += 1 # k : 앞부분 a[]에서 덮어씌워지는 지점
            
            while j < p: # i <= right 가 더이상 성립하지 않는 경우 -> buff[]에 아직 값이 남아있단 이야기이므로
                # buff[]에 남은 값을 a[] 뒤에 덮어씌운다. 
                a[k] = buff[j]
                k += 1
                j += 1
                
            # 반대로 j < p 가 더이상 성립하지 않는 경우 -> a[]의 남은 값은 그대로 있는게 맞으므로 생각하지 않는다.

    n = len(a)
    buff = [None] * n # 작업용 배열을 생성
    _merge_sort(a, 0, n-1)
    del buff # 작업용 배열 소멸

if __name__ == '__main__':
    print('병합 정렬 수행')
    num = int(input('원소 수를 입력하세요.: '))
    x = [None] * num # 원소수 num인 배열 생성
    
    for i in range(num) :
        x[i] = int(input(f'x[i]: '))

merge_sort(x)

print('오름차순 정렬됨')
for i in range(num):
    print(f'x[{i}] = {x[i]}')
