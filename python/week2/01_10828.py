import sys

n = int(sys.stdin.readline())

stk = []
cnt = -1
for _ in range (n) :
    s = sys.stdin.readline().split()
    
    if s[0] == 'push' :
        stk.append(s[1])
        cnt += 1
    elif s[0] == 'pop' :
        if cnt >= 0 :
            print(stk[cnt])
            stk.pop()
            cnt -= 1
        else :
            print(cnt)
    elif s[0] == 'size' :
        print(cnt+1)
    elif s[0] == 'empty' :
        if cnt >=0 :
            print(0)
        else :
            print(1)
    elif s[0] == 'top' :
        if cnt >= 0 :
            print(stk[cnt])
        else :
            print(cnt)    

