import sys # 시간초과 (재귀 풀이)

n = int(sys.stdin.readline())

arr = [int(sys.stdin.readline()) for _ in range(n)]
    
dp = [-1 for _ in range (n)]

def stair(idx) :
    if idx == 0 :
        return arr[0]
    if idx == 1 :
        return arr[0] + arr[1]
    if idx == 2 :
        return max(arr[0] + arr[2], arr[1] + arr[2])
    
    if dp[idx] != -1:
        return dp[idx]
    
    dp[idx] = max(stair(idx-2) + arr[idx], stair(idx-3) + arr[idx-1] + arr[idx])
    return dp[idx]
    
print(stair(n-1))

