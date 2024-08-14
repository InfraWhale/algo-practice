# 정렬 1

import sys
sys.setrecursionlimit(10**6) # 2751번 기준, 70%에서 RecursionError 발생한다.
#그런데 위에꺼 추가 시, pypy3에서 바로 메모리초과 발생한다.
#python3에서 70%에서 시간초과 발생하는 것으로 보아, 퀵소트의 시간복잡도가 O(N^2)인 테스트 케이스가 있는 것으로 보인다.

n = int(sys.stdin.readline())
arr = []
for i in range(n) :
    arr.append(int(sys.stdin.readline()))
    
def qsort(a : list, left: int, right: int) -> None :
    
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

qsort(arr, 0, n-1)

for i in arr :
    print(i)