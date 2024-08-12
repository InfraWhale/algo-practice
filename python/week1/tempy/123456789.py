import sys
n = int(sys.stdin.readline().strip())
data=[0]*n
for i in range(n):
    data[i]=list(map(int,sys.stdin.readline().strip().split()))
# 4
# 0 10 15 20
# 5 0 9 10
# 6 13 0 12
# 8 8 9 0
def cost_cal(arr, cost_matrix): # ex result[0]이 매개변수로 들어오면 list 0 1 2 3
    total_cost = 0
    for i in range(len(arr)):
        pos = arr[i]
        des = arr[(i+1)%len(arr)] # index out of range 해결해야됨 마지막 번호 초과
        if cost_matrix[pos][des] == 0:  # 갈 수 없는 경로
            return float('inf')
        cost = cost_matrix[pos][des]
        total_cost +=cost
    return total_cost
# print(data)
result = []
check = [0]*len(data)
temp = []
Minimum = float('inf')  #무한대 설정법
def des_perm(des, start): #des 도달해야 하는 목적지수 n출발인덱스
    
    if des == start: # ex 목적지 4  출발 0
        # print(list(temp))
        ret = cost_cal(temp,data)
        global Minimum
        Minimum = min(Minimum, ret)
        return
    
    for i in range(des): #0부터 도시수 끝까지
        if check[i]:
            continue
        check[i]=1
        temp.append(i) #체킹하고 임시배열 저장
        des_perm(des,start+1)
        check[i]=0
        temp.pop()
des_perm(n,0)
# print(result)
# 목적지 순열 생성 확인완료
# y=cost_cal(result,data)
print(Minimum)
#경로비용 계산함수 확인