import sys

n = int(sys.stdin.readline())

que = []
first = 0
last = 0
for _ in range (n) :
    s = sys.stdin.readline().split()
    
    if s[0] == 'push' :
        que.append(s[1])
        last += 1
        
    elif s[0] == 'pop' :
        if first == last :
            print(-1)
        else :
            print(que[first])
            first += 1
            
    elif s[0] == 'size' :
        print(last-first)
    
    elif s[0] == 'empty' :
        if first == last :
            print(1)
        else :
            print(0)
    
    elif s[0] == 'front' :
        if first == last :
            print(-1)
        else :
            print(que[first])

    elif s[0] == 'back' :
        if first == last :
            print(-1)
        else :
            print(que[last-1]) 