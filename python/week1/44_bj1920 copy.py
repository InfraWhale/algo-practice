import sys
sys.setrecursionlimit(10**6)

# 메모리 초과...

n = (int(sys.stdin.readline()))
n_arr = list(map(int, sys.stdin.readline().split()))

m = (int(sys.stdin.readline()))
m_arr = list(map(int, sys.stdin.readline().split()))

n_arr.sort()

def find(start, end, want) :
    #print("start, end, want : ", start, end, want)
    if start == end :
        if want == n_arr[start] :
            print(1)
            return
            #return 1
        else :
            print(0)
            return
            #return 0
    
    mid = (start + end) // 2
    #print("mid : ", mid)
    if want == n_arr[mid] :
        print(1)
        return
        #return 1
    elif want < n_arr[mid] :
        find(start, mid-1, want)
        return
    else :
        find(mid+1, end, want)
        return
    
for i in m_arr :
    find(0, n-1, i)
    #print(find(0, n-1, i))