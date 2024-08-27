import sys
# 25% 틀렸습니다. -> 맞았습니다.
INF = float('Inf')

n, k = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
multi = []

ret = 0

for i in range (k) :
    now_item = arr[i]
    if len(multi) < n : # 멀티탭 공간있으면
        if now_item in multi :
            continue
        else :
            multi.append(now_item)
        #print("multi append : ", multi)
    else : # 멀티탭 꽉차있으면
        if now_item in multi : # 멀티탭에 쓰려는게 이미 꽃혀있으면
            continue
        else : # 멀티탭에 쓰려는게 없으면
            remove_item = -1
            remove_idx = -1
            
            # 더 나중에 쓰이는 것을 뺴주기    
            for item in multi : 
                item_idx = k+1
                for j in range (i+1, k) : 
                    if arr[j] == item :
                        item_idx = j
                        break
                if remove_idx < item_idx :
                    remove_idx = item_idx
                    remove_item = item
            
            multi.remove(remove_item)
            #print("multi remove : ", multi)
            ret += 1
            
            multi.append(now_item)
            #print("multi append : ", multi)
print(ret)