#더 깔끔하게 못푸나...?

import sys
n = int(sys.stdin.readline())
n_arr = list(map(int,sys.stdin.readline().split()))
c_arr = []
c_arr_pre = list(map(int,sys.stdin.readline().split()))
for i in range(4) :
    for j in range (c_arr_pre[i]) :
        c_arr.append(i)
#print("c_arr : ", c_arr)

picked = []
used = [0]*(n-1)

max_val = -1000000000
min_val = 1000000000

def get_sum(a) :
    sum = n_arr[0]
    for i in range (0, n-1) :
        if a[i] == 0 :
            sum += n_arr[i+1]
        elif a[i] == 1 :
            sum -= n_arr[i+1]
        elif a[i] == 2 :
            sum *= n_arr[i+1]
        elif a[i] == 3 :
            if(sum < 0) :
                sum = -(-sum // n_arr[i+1])
            else :
                sum //= n_arr[i+1]
    #print("sum : ", sum)
    return sum

def get_sec(depth, ret) :
    if depth == n-1 :
        temp = get_sum(picked)
        #print("picked : ", picked)
        return ( max(ret[0], temp), min(ret[1], temp) ) # 최대최소 비교
    
    for i in range (n-1) :
        if used[i] == 1 :
            continue
        
        picked.append(c_arr[i])
        used[i] = 1
        
        ret = get_sec(depth + 1, ret)
        
        picked.pop()
        used[i] = 0
    return ret

ret = get_sec(0, (max_val,min_val))

print(ret[0])
print(ret[1])