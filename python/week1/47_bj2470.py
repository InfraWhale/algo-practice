import sys

#투포인터를 사용

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

arr.sort()
start = 0
end = n-1

val1 = start
val2 = end

pre_sum = float('inf')  # 초기값을 무한대로 설정

while (start < end) :
    sum = arr[start] + arr[end]
    
    if pre_sum > abs(sum) :
        pre_sum = abs(sum)
        val1 = start
        val2 = end
    
    if sum < 0 :
        start += 1
    elif sum > 0 :
        end -= 1
    else :
        break
        
print(arr[val1], arr[val2])