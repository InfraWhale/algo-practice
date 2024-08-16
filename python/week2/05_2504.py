import sys

str = sys.stdin.readline().strip()
stk = []
arr = [[] for i in range(30)]

depth = -1
for i in range (len(str)) :
    temp = str[i]
    
    if len(stk) == 0 : #스택에 하나도 없는 경우
        stk.append(temp)
        depth += 1
    
    elif stk[-1] == '(' and temp == ')': # 스택에 () 만나는경우
        if(len(arr[depth+1]) == 0) :
            arr[depth].append(2)
        else :
            sum_val = 0
            for it in arr[depth+1] :
                sum_val += it
            arr[depth+1] = []
            arr[depth].append(2*sum_val)
        stk.pop()
        depth -= 1
    
    elif stk[-1] == '[' and temp == ']': # 스택에 [] 만나는경우
        if(len(arr[depth+1]) == 0) :
            arr[depth].append(3)
        else :
            sum_val = 0
            for it in arr[depth+1] :
                sum_val += it
            arr[depth+1] = []
            arr[depth].append(3*sum_val)
        stk.pop()
        depth -= 1
    
    else :
        stk.append(temp)
        depth += 1

    # print(depth)
    # print(arr)
    
if len(stk) != 0 :
    print(0)
else :
    sum_val = 0
    for it in arr[0] :
        sum_val += it
    print(sum_val)