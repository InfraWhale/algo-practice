import sys

INF = float('Inf')

n, k = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
multi = []
arr_cnt = [0]*(k+1)

ret = 0

for it in arr :
    arr_cnt[it] += 1

for i in arr :
    if len(multi) < n : # 멀티탭 공간있으면
        multi.append(i)
        print("multi append : ", multi)
        arr_cnt[i] -= 1
    else : # 멀티탭 꽉차있으면
        if i in multi : # 멀티탭에 쓰려는게 이미 꽃혀있으면
            arr_cnt[i] -= 1
        else : # 멀티탭에 쓰려는게 없으면
            min_cnt = INF
            min_idx = -1
            
            for j in multi : 
                if arr_cnt[j] < min_cnt :
                    min_cnt = arr_cnt[j]
                    min_idx = j
                elif arr_cnt[j] == min_cnt :
                    pass
                    
                    # 더 나중에 쓰이는 것을 뺴주기    
                
            
            multi.remove(min_idx)
            print("multi remove : ", multi)
            ret += 1
            
            multi.append(i)
            print("multi append : ", multi)
            arr_cnt[i] -= 1
# print("arr_cnt : ", arr_cnt)
print(ret)