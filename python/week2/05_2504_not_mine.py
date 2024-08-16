str = input()
arr = []
answer = 0
tmp = 1
for i, s in enumerate(str):
    if s == '(' :
        arr.append(s)
        tmp *= 2
    elif s == '[' :
        arr.append(s)
        tmp *= 3
    elif s == ')':
        if len(arr) == 0 or arr[-1] != '(':
            answer = 0
            break
        if str[i-1] == '(':
            answer += tmp
        arr.pop()
        tmp //= 2
    elif s == ']':
        if len(arr) < 1 or arr[-1] != '[':
            answer = 0
            break
        if str[i-1] == '[':
            answer += tmp
        arr.pop()
        tmp //= 3
if len(arr) != 0:
    print(0)
else:
    print(answer)