import sys
arr = []
sum = 0
for i in range(9) :
    arr.append(int(sys.stdin.readline()))
    sum += arr[i]

arr.sort()

for i in range (9) :
    for j in range (i+1, 9) :
        if sum - arr[i] - arr[j] == 100 :
            for k in range (9) :
                if k != i and k != j :
                    print(arr[k])
            exit()