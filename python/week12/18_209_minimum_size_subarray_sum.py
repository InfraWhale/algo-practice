class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        ln = len(nums)
        
        for cnt in range (1, ln+1) :
            
            sum_val = 0
            for i in range (cnt) :
                sum_val += nums[i]
            
            for i in range (ln - cnt + 1) :
                if sum_val >= target :
                    return cnt
                if i >= ln - cnt :
                    break
                sum_val = sum_val - nums[i] + nums[i+cnt]
            
        return 0
        
solution = Solution()
target = 11
nums = [1,2,3,4,5]
print(solution.minSubArrayLen(target, nums))
    