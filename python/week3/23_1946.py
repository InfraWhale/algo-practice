import sys
# 4% 시간초과 -> 맞았습니다. (N^2 -> N)
t = int(sys.stdin.readline())

for i in range (t) :
    n = int(sys.stdin.readline())

    arr = [tuple(map(int, sys.stdin.readline().split())) for _ in range (n)]
    count = 1
    
    arr.sort(key = lambda x : (x[0], x[1]))
    
    now_pap, now_int = arr[0]
    
    for i in range (1, n) :
        if arr[i][1] < now_int :
            count += 1
            now_pap, now_int = arr[i]
                
    print(count)
