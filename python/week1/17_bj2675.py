# 좀 헷갈렸음

a = int(input())

for i in range (a) :
    ret = ""
    cntStr, str = input().split()
    cnt = int(cntStr)
    for j in range (len(str)) :
        for k in range(cnt) :
            ret += str[j]
    print(ret)