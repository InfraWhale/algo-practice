# 힌트보고 품
class Solution:
    def maximumTripletValue(self, nums: list[int]) -> int:
        ln_nums  = len(nums)
        
        prefix_max = [0 for _ in range(ln_nums)]
        suffix_max = [0 for _ in range(ln_nums)]
        prefix_max[0] = nums[0]
        suffix_max[ln_nums-1] = nums[ln_nums-1]
        
        for i in range (1, ln_nums) :
            prefix_max[i] = max(nums[i], prefix_max[i-1])
            suffix_max[ln_nums-1-i] = max(nums[ln_nums-1-i], suffix_max[ln_nums-i])
            
        max_val = 0
        for i in range(1, ln_nums-1) :
            now_sum = (prefix_max[i-1] - nums[i]) * suffix_max[i+1]
            max_val = max(max_val, now_sum)

        return max_val
    
solution = Solution()
nums = [12,6,1,2,7]
print(solution.maximumTripletValue(nums))