n, x = map(int, input().split())
arr = list(map(int, input().split()))
ret = []
for i in range(n) :
    if x > arr[i] :
        ret.append(arr[i])

print(*ret)