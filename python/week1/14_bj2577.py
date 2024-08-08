a = int(input())
b = int(input())
c = int(input())

total = a*b*c
totalStr = str(total)
arr = [0 for i in range(10)]

for i in range(len(totalStr)) :
    arr[int(totalStr[i])] += 1

for i in range(len(arr)) :
    print(arr[i])