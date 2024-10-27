class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0 for _ in range (n+1)]
        dp[0] = 1
        dp[1] = 1
        
        def stairs(no) :
            if dp[no] != 0 :
                return dp[no]
            
            if dp[no-1] != 0 and dp[no-2] != 0 :
                dp[no] = dp[no-1] + dp[no-2]
                return dp[no]
            
            return stairs(no-1) + stairs(no-2)
        
        return stairs(n)

solution = Solution()
n = 3
print(solution.climbStairs(n))
    