import sys
import heapq
#이전 풀이는 진입차수가 0인 것부터 계산했음
#진입차수가 아니라 진출차수가 0인 것으로 생각해서 풀기
#https://velog.io/@whddn0221/%EB%B0%B1%EC%A4%80-1432-%EA%B7%B8%EB%9E%98%ED%94%84-%EC%88%98%EC%A0%95-%EC%9C%84%EC%83%81%EC%A0%95%EB%A0%AC-%EC%9A%B0%EC%84%A0%EC%88%9C%EC%9C%84-%ED%81%90-mrltwcp5
# 위 블로그 참고
n = int(sys.stdin.readline())

arr_in = [[] for _ in range (n+1)] # 진입하는 노드들을 저장
arr_out = [0]*(n+1) # 진출차수를 저장
ret_arr = [0]*(n+1) # 결과를 저장

for i in range (n) :
    temp = sys.stdin.readline().strip()
    for j in range (n) :
        if temp[j] == '1':
            arr_in[j+1].append(i+1)
            arr_out[i+1] += 1

def topology_sort(no) :
    que = []
    
    for it in range (1, n+1) :
        if arr_out[it] == 0 :
            heapq.heappush(que, -it)
    while que :
        now = -heapq.heappop(que)
        ret_arr[now] = no

        for next in arr_in[now] :
            arr_out[next] -= 1
            if arr_out[next] == 0 :
                heapq.heappush(que, -next)
        no -= 1

    return

topology_sort(n)

if ret_arr.count(0) > 2 : # ret_arr에 들어오지 않은 값 발생 -> -1 출력
    print(-1)
else :
    print(*ret_arr[1:])