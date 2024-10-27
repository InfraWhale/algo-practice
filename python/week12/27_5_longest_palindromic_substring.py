#품
class Solution:
    def longestPalindrome(self, s: str) -> str:
        ln_str = len(s)
        
        if ln_str == 1 :
            return s
        
        dp = [[0 for _ in range(ln_str)] for _ in range(ln_str)]
        dp_str = [["" for _ in range(ln_str)] for _ in range(ln_str)]
        
        max_val = 1
        max_idx = (0, 0)
        
        for i in range(ln_str) :
            dp[i][i] = 1
            dp_str[i][i] = s[i]
            
            if i+1 < ln_str and s[i] == s[i+1] :
                dp[i][i+1] = 2
                dp_str[i][i+1] = s[i] + s[i]
                if max_val < dp[i][i+1] :
                    max_val = dp[i][i+1]
                    max_idx = (i, i+1)
                
        for length in range (3, ln_str+1) :
            for i in range(ln_str-length+1) :
                if dp[i+1][i+length-2] != 0 and s[i] == s[i+length-1]:
                    dp[i][i+length-1] = dp[i+1][i+length-2] + 2
                    dp_str[i][i+length-1] = s[i] + dp_str[i+1][i+length-2] + s[i]
                    if max_val < dp[i][i+length-1] :
                        max_val = dp[i][i+length-1]
                        max_idx = (i, i+length-1)
        
        return dp_str[max_idx[0]][max_idx[1]]
    

solution = Solution()
s = "ccc"
print(solution.longestPalindrome(s))
    