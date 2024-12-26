import sys

l, r= map(int, sys.stdin.readline().split())

str_l = str(l)
str_r = str(r)

if len(str_l) != len(str_r) :
    print(0)
else :
    ret = 0

    for i in range (0, len(str_l)) :
        if str_l[i] == '8' and str_r[i] == '8' :
            ret += 1
        else :
            if(str_l[i] == str_r[i]) :
                continue
            break
    
    print(ret)