import sys

m, n, l = map(int,sys.stdin.readline().split())
arr_m = list(map(int, sys.stdin.readline().split())) # 사수 리스트
arr_n = [] # 동물 리스트
for i in range (n) :
    arr_n.append(tuple(map(int, sys.stdin.readline().split())))
arr_m.sort()
arr_n.sort()
cnt = 0

def can_hunt(prey_x, prey_y, hunter_x) :
    return (abs(prey_x - hunter_x) + prey_y) <= l
    

def find_hunter(x, y) : # 해당 좌표 사냥 가능하면 True, 아니면 False
    
    start = 0
    end = m-1
    
    while start <= end :
        mid = (start+end) // 2
        hunter_pos = arr_m[mid]
        if can_hunt(x, y, hunter_pos) :
            return True
        
        if hunter_pos > x :
            end = mid - 1
        else :
            start = mid + 1
    return False

for i in range(n) :
    if arr_n[i][1] > l :
        continue
    else :
        if find_hunter(arr_n[i][0], arr_n[i][1]) :
            cnt += 1

print(cnt)
