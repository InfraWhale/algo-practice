class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        chunk = k // (n-1)
        remain = k % (n-1)
        if chunk % 2 == 0 :
            return remain
        else :
            return (n-1) - remain
            

solution = Solution()
n = 5
k = 6
print(solution.numberOfChild(n, k))

# https://leetcode.com/submissions/detail/1431965918/