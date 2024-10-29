class Solution:
    def findNonMinOrMax(self, nums: list[int]) -> int:
        nums.sort()
        min_val = nums[0]
        max_val = nums[-1]
        
        for i in range (len(nums)) :
            if nums[i] != min_val and nums[i] != max_val :
                return nums[i]
        
        return -1
    
solution = Solution()
nums = [3,2,1,4]
print(solution.findNonMinOrMax(nums))

#https://leetcode.com/submissions/detail/1436758203/