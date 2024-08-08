a = int(input())

for i in range(a) :
    arr = list(map(int, input().split()))
    total = 0
    cnt = 0
    for j in range(arr[0]) :
        total += arr[j+1]
    avg = total/arr[0]
    
    for j in range(arr[0]) :
        if arr[j+1] > avg :
            cnt += 1
    print("{:.3f}%".format(cnt/arr[0]*100))