import sys
n = int(sys.stdin.readline())
arr = []
for i in range (n) :
    arr.append(list(map(int,sys.stdin.readline().split())))
    
w_cnt = 0
b_cnt = 0

def go(y, x, length) :
    global w_cnt
    global b_cnt
    #print ("y, x, length : ", y, x, length)
        
    if length == 1 :
        if arr[y][x] == 0 :
            w_cnt += 1
        else :
            b_cnt += 1
        return
    
    prev = 2
    flag = True
    for i in range (y, y+length) :
        for j in range (x, x+length) :
            if prev == 2 or arr[i][j] == prev :
                prev = arr[i][j]
            else :
                flag = False
                break
        if flag == False :
            break
        
    if flag == True :
        #print ("prev : ", prev)
        if prev == 0 :
            w_cnt += 1
            #print ("w_cnt : ", w_cnt)
        else :
            b_cnt += 1
    else :
        new_len = length // 2 
        go(y, x, new_len)
        go(y+new_len, x, new_len)
        go(y, x+new_len, new_len)
        go(y+new_len, x+new_len, new_len)
    return

go(0, 0, n)

print(w_cnt)
print(b_cnt)

