# 다시 풀어볼것

import sys

n, r, c = map(int,sys.stdin.readline().split())

def rec(row, column, depth, add):
    # 기저사례
    # print("row, column:",row, column)
    
    
    if (row==0 and column==0) or depth == 0 :
        print(add)
        exit()
    add_plus = 4**(depth-1)
    length = 2**depth
    if(r < length/2 and c < length/2) :
        rec(row, column, depth-1, add + 0*add_plus)
    elif(r < length/2 and c >= length/2) :
        rec(row, column-length/2, depth-1, add + 1*add_plus)
    elif(r >= length/2 and c < length/2) :
        rec(row-length/2, column, depth-1, add + 2*add_plus)
    else :
        rec(row-length/2, column-length/2, depth-1, add + 3*add_plus)
    return

rec(r, c, n, 0)