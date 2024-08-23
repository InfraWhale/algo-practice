import sys
str = sys.stdin.readline().strip()

num_arr = []
pm_arr = []

temp = ''

for i in range (len(str)) :
    if str[i] == '-' or str[i] == '+' :
        pm_arr.append(str[i])
        num_arr.append(int(temp))
        temp = ''
    else :
        temp += str[i]
num_arr.append(int(temp))

sum = 0
flag = False

for i in range (len(num_arr)) :
    if i == 0 :
        sum += num_arr[i]
    else :
        if pm_arr[i-1] == '-' :
            flag = True
        if flag :
            sum -= num_arr[i]
        else :
            sum += num_arr[i]
            
print(sum)