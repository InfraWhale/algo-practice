# 다른 풀이 보면 좋을듯
a, b = map(int, input().split())
strA = str(a)
strB = str(b)
ret = ""

for i in range (2, -1, -1) :
    if (strA[i] > strB[i]):
        ret = strA
        break
    elif (strA[i] < strB[i]):
        ret = strB
        break

for i in range (2, -1, -1) :
    print(ret[i], end="")


