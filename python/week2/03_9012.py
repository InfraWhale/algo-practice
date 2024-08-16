import sys

k = int(sys.stdin.readline())

for _ in range(k) :
    str = sys.stdin.readline().strip()
    stk = []
    for i in range (len(str)) :
        temp = str[i]
        if len(stk) == 0 :
            stk.append(temp)
        elif stk[-1] == '(' and temp == ')':
            stk.pop()
        else :
            stk.append(temp)

    if len(stk) == 0 :
        print("YES")
    else :
        print("NO")