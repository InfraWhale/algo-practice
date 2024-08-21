import sys

n = int(sys.stdin.readline())
arr_circle = []
for i in range (n) :
    c, r = map(int, sys.stdin.readline().split())
    arr_circle.append(("L", c-r))
    arr_circle.append(("R", c+r))
    
arr_circle.sort(key=lambda x: (x[0]), reverse = True)
arr_circle.sort(key=lambda x: x[1])
    
stk = []
count = 1

for circle in arr_circle :
    
    circle_type, circle_val = circle
    
    if circle_type == "L":
        stk.append(circle)
    else : # if circle_type == "R":
        sum_width_inner_circle = 0
        
        while stk:
            
            prev_type, prev_val = stk.pop()
            
            if prev_type == "L" :
                width = circle_val - prev_val # 현재 만들어진 원의 너비
                
                if sum_width_inner_circle == width :
                    count += 2
                else :
                    count += 1
                
                stk.append(("C", width))
                
                break # 원이 만들어진 경우 다음 arr_circle의 요소로 간다.
            
            elif prev_type == "C" :
                sum_width_inner_circle += prev_val
                
print(count)