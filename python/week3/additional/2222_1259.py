import sys

while True :
    str = sys.stdin.readline().strip()
    if str == '0' :
        break
    else :
        length = len(str)
        flag = True
        mid = length//2
        if length % 2 == 1 : # 홀수면
            for i in range (1, (length//2+1)) :
                if str[mid-i] != str[mid+i] :
                    flag = False
                    break
        else : # 짝수면
            for i in range (0, (length//2)) :
                if str[mid-1-i] != str[mid+i] :
                    flag = False
                    break
        
        if flag :
            print("yes")
        else :
            print("no")