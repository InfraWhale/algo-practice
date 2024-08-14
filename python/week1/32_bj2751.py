# 정렬 2

import sys

n = int(sys.stdin.readline())
arr = []
for i in range(n) :
    arr.append(int(sys.stdin.readline()))

buff = [None] * n # 작업용 배열을 생성
    
def merge_sort(a: list, left: int, right: int) -> None:
    
        if left < right:
            center = (left + right) // 2
            
            merge_sort(a, left, center) #배열 앞부분을 병합 정렬
            merge_sort(a, center + 1, right) # 배열 뒷부분을 병합 정렬
            
            p = j = 0
            i = k = left
            
            while i <= center: # a[]의 분할된 위치의 시작부터 중앙까지 꺼내서 buff[]에 넣는다.
                buff[p] = a[i]
                p += 1
                i += 1
                                
            while i <= right and j < p: # a[]의 앞 절반이 담긴 buff[]와 a[]의 뒷 절반을 합친다.

                if buff[j] <= a[i]:
                    a[k] = buff[j] # buff[]의 처음부터 시작하여, a[]의 분할된 배열의 시작지점부터 덮어씌운다
                    j += 1
                else :
                    a[k] = a[i] # a[]의 중간부터 시작하여, a[]의 분할된 배열의 시작지점부터 덮어씌운다
                    i += 1
                k += 1
            
            while j < p: # i <= right 가 더이상 성립하지 않는 경우 -> buff[]에 남은 값을 a[] 뒤에 덮어씌운다.
                a[k] = buff[j]
                k += 1
                j += 1

merge_sort(arr, 0, n-1)

for i in arr :
    print(i)