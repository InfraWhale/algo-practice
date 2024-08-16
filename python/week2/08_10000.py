import sys

n = int(sys.stdin.readline())
arr = []
for i in range (n) :
    c, r = map(int, sys.stdin.readline().split())
    arr.append((i, c-r))
    arr.append((i, c+r))
    
stk = []
arr.sort(key = lambda x:x[1])

#print(arr)

# 3
# 2 2
# 1 1
# 3 1
# [(0, 0), (1, 0), (1, 2), (2, 2), (0, 4), (2, 4)]

cnt = 1
for _ in range (n*2) :
    if not stk : #스택에 하나도 없는 경우
        stk.append(arr[i])
    
    elif stk[-1][0] == arr[i][0]: # 원이 마무리되는 경우
        cnt += 1
        now_len = arr[i][1] - stk[-1][1]
    
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