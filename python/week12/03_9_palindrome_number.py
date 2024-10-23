class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 :
            return False
        st = str(x)
        ln = len(st)
        for i in range (ln // 2) :
            if st[i] != st[ln-1-i] :
                return False
        return True
    
solution = Solution()
x = 121
print(solution.isPalindrome(x))