# 다시 풀어볼것

import sys

n, r, c = map(int,sys.stdin.readline().split())

def rec(row, column, depth, add):
    #print("row, column:",row, column)
    
    # 기저사례
    if depth == 0 :
        print(add)
        exit()
    
    add_plus = 4**(depth-1)
    length = 2**depth
    l = length//2
    #print("l : ", l)
    
    if(row < l and column < l) :
        rec(row, column, depth-1, add + 0*add_plus)
    elif(row < l and column >= l) :
        rec(row, column-l, depth-1, add + 1*add_plus)
    elif(row >= l and column < l) :
        rec(row-l, column, depth-1, add + 2*add_plus)
    else :
        rec(row-l, column-l, depth-1, add + 3*add_plus)
    return

rec(r, c, n, 0)