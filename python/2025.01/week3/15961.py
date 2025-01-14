import sys # 1% 틀렸습니다 ... 반례를 못찾겠음
# 없으면 주방장이 하나 만들어준다는걸 읽질 못함 ... 문제 더 꼼꼼히 읽기
# 2 2 2 2
# 1
# 1
# => 2

n, d, k, c = map(int, sys.stdin.readline().split()) # 접시 수, 초밥 가짓수, 연속으로 먹는 접시 수, 쿠폰번호
dishes = []
used = [0 for i in range(d+1)]

cnt = 0

for _ in range (k) :
    dish = int(sys.stdin.readline())
    dishes.append(dish)
    if used[dish] == 0 :
        cnt += 1
    used[dish] += 1

for _ in range (n-k) :
    dish = int(sys.stdin.readline())
    dishes.append(dish)

ret = cnt
if n > k and used[c] == 0 :
    ret += 1

if ret == k+1 :
    print(ret)
    exit()
    
for start in range(1, n) :
    end = start + k - 1
    if end >= n :
        end -= n
    
    used[dishes[end]] += 1
    if used[dishes[end]] == 1 :
        cnt += 1
    used[dishes[start-1]] -= 1
    if used[dishes[start-1]] == 0 :
        cnt -= 1

    if used[c] == 0 :
        ret = max(ret, cnt+1)
    else :
        ret = max(ret, cnt)
    if ret == k+1 :
        break

print(ret)