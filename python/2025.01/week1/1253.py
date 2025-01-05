import sys # 15% 틀렸습니다.

n = int(sys.stdin.readline())

arr = list(map(int, sys.stdin.readline().split()))

arr.sort()

# print(arr)

good_dic = {}
bad_dic = {}

for i in range(n) :
    for j in range(i+1, n):
        sum_val = arr[i] + arr[j] 
        if sum_val in good_dic or sum_val in bad_dic:
            continue
            
        start = 0
        end = n-1
        
        while start <= end :
            mid = (start+end) // 2
            if sum_val < arr[mid] :
                end = mid-1
            elif sum_val > arr[mid] :
                start = mid+1
            else :
                good_dic[sum_val] = 1
                break
        
        if sum_val not in good_dic :
            bad_dic[sum_val] = 1

# print(good_dic)
print(len(good_dic))