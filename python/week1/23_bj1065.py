import sys

a = int(sys.stdin.readline())
cnt = 0

if a < 100 :
    print(a)
else :
    cnt = 99
    for i in range (100, a+1) :
        if i == 1000 : 
            continue
        b = i // 100
        c = (i - (b*100)) // 10
        d = i - (b*100) - (c*10)
        
        # print("b, c, d : ",b, c, d)
        
        if (b-c) == (c-d) :
            cnt +=1
    print(cnt)

    