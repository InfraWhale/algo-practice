import sys

INF = float('Inf')
dp = []

def w (a, b, c) :
    

    
    if  a <= 0 or b <= 0 or c <= 0 :
        return 1
    
    elif a> 20 or b > 20 or c > 20 :
        return w(20, 20, 20)
    
    elif dp[a][b][c] != INF :
        return dp[a][b][c]
    
    elif a < b and b < c :
        dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
        return dp[a][b][c]
    
    else :
        dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
        return dp[a][b][c]


while True: 
    x, y, z = map(int, sys.stdin.readline().split())
    
    if x == -1 and y == -1 and z == -1 :
        break
    
    dp = [[[INF for x in range(21)] for y in range(21)] for z in range(21)]
    
    ret = w(x, y, z)
    
    print("w(%d, %d, %d) = %d" % (x, y, z, ret) )
    
