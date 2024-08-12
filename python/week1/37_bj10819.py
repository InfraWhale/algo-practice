import sys
n = int(sys.stdin.readline())

arr = list(map(int,sys.stdin.readline().split()))

picked = []
visited = [0]*8

def get_sum(a) :
    sum = 0
    for i in range (0, len(a)-1) :
        sum += abs(a[i+1] - a[i])
    return sum

def mix(depth, ret) :
    if depth == n :
        ret = max(ret, get_sum(picked))
        print("@", picked, get_sum(picked))
        return ret
    
    for i in range (n) :
        if visited[i] == 1 :
            continue
        
        picked.append(arr[i])
        visited[i] = 1
        
        ret = mix(depth + 1, ret)
        
        picked.pop()
        visited[i] = 0
    return ret
    
print(mix(0, 0))