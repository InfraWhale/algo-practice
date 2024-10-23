#답봄

class Solution:
    def find132pattern(self, nums: list[int]) -> bool:
        ln = len(nums)
        if ln < 3 :
            return False
        
        stk = []
        third = float("-Inf")
        
        for i in range (ln - 1, -1, -1) :
            if nums[i] < third :
                return True
            while stk and nums[i] > stk[-1] :
                third = stk.pop()
            stk.append(nums[i])
        return False

solution = Solution()
# nums = [3,1,4,2]
nums = [9, 15, 7, 8, 9, 10]
print(solution.find132pattern(nums))
    