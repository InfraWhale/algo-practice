import sys
sys.setrecursionlimit(10**9)
arr = []
 # 트리 안만들고 풀었는데 다시 생각해보기
while True: # 입력의 수가 주어지지 않았을 때 여러줄 배열에 입력하기
    try:
        arr.append(int(sys.stdin.readline()))
    except:
        break
def make_who_wee(start, end) :
    first_val = arr[start]
    if start == end :
        print(first_val)
        return
    
    if arr[start+1] > first_val:
        low_idx = -1
        high_idx = start+1
    else :
        low_idx = start+1
        high_idx = end+1
        for i in range(start+1, end+1) :
            if arr[i] > first_val :
                high_idx = i
                break
    
    if low_idx != -1 : # first_val보다 작은 숫자 있는 경우
        make_who_wee(low_idx, high_idx-1)
    if high_idx != end+1 : 
        make_who_wee(high_idx, end)
    
    print(first_val)
    return

make_who_wee(0, len(arr)-1)