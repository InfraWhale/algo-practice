import sys
#풀이 보고 적은 답
while True : 
    arr_bar = list(map(int, sys.stdin.readline().split()))
    if arr_bar[0] == 0 :
        break
    else :
        stk = []
        max_val = 0
        
    for i in range(len(arr_bar)) :
        if i == 0 :
            continue
        
        now_idx = i
        now_height = arr_bar[i]
        
        if stk and stk[-1][1] > now_height : # 스택 마지막 요소 높이
            while True :
                prev_height = stk.pop()[1]
                width_start = 1
                if stk :
                    width_start = stk[-1][0]+1 # 스택 마지막 요소 인덱스 다음
                result = (now_idx - width_start) * prev_height
                max_val = max(max_val, result)
                
                if not stk or stk[-1][1] <= now_height:
                    break
        
        if not stk or stk[-1][1] <= now_height:
            stk.append((now_idx, now_height))
    
    while stk :
        prev_height = stk.pop()[1]
        width_start = 1
        if stk :
            width_start = stk[-1][0]+1
        result = (arr_bar[0]+1 - width_start) * prev_height
        max_val = max(max_val, result)
        
    print(max_val)