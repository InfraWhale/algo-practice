import sys
import heapq
# 답을 봐도 모르겠다...!

n = int(sys.stdin.readline())

arr_out = [[] for _ in range (n+1)]
arr_in =[0]*(n+1)
ret_arr = [0]
for i in range (n) :
    temp = sys.stdin.readline().strip()
    for j in range (n) :
        if temp[j] == '1':
            arr_out[i+1].append(j+1)
            arr_in[j+1] += 1

def topology_sort() :
    que = []
    
    for it in range (1, n+1) :
        if arr_in[it] == 0 :
            que.append(it)
    while que :
        for _ in range (len(que)) :
            now = heapq.heappop(que)
            ret_arr.append(now)
            
            for next in arr_out[now] :
                arr_in[next] -= 1
                if arr_in[next] == 0 :
                    heapq.heappush(que, next)
    return

topology_sort()

if len(ret_arr) != (n+1) : # ret_arr에 들어오지 않은 값 발생 -> -1 출력
    print(-1)
else :
    ret_arr_2 =[0]*(n+1)
    for i in range (1, n+1) :
        ret_arr_2[ret_arr[i]] = i # 값과 인덱스를 바꾼 새로운 배열을 만든다.
    
    for i in range (1, n+1) :
        print(ret_arr_2[i], end=" ")