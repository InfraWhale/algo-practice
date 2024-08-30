import sys
n = int(sys.stdin.readline())

arr_paper = [list(map(int, sys.stdin.readline().split())) for _ in range (n)]

arr_ret = [0, 0, 0]

def go (y, x, leng) :
    start = arr_paper[y][x]
    
    if len == 1 :
        arr_ret[start+1] += 1
        return
    
    flag = True
    for i in range (y, y+leng) :
        for j in range(x, x+leng) :
            if i == y and j == x :
                continue
            if arr_paper[i][j] != start :
                flag = False
                break
        if flag == False :
            break
    
    if flag == False :
        next_leng = leng // 3
        go(y, x, next_leng)
        go(y, x+next_leng, next_leng)
        go(y, x+(next_leng*2), next_leng)
        go(y+next_leng, x, next_leng)
        go(y+next_leng, x+next_leng, next_leng)
        go(y+next_leng, x+(next_leng*2), next_leng)
        go(y+(next_leng*2), x, next_leng)
        go(y+(next_leng*2), x+next_leng, next_leng)
        go(y+(next_leng*2), x+(next_leng*2), next_leng)
        
    else :
        arr_ret[start+1] += 1
        
    return

go(0, 0, n)

for it in arr_ret :
    print(it)