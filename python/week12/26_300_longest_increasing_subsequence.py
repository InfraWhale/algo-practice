# 품
class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        dp_next = [ nums[i] for i in range(len(nums))]
        dp_len = [ 1 for _ in range(len(nums))]
        
        mav_val = 1
        for length in range (2, len(nums)+1) :
            for start in range(len(nums)-length+1) :
                end = start + length - 1
                if nums[end] > dp_next[start] :
                    dp_next[start] = nums[end]
                    dp_len[start] += 1
                    mav_val = max(mav_val, dp_len[start])
    
        print(dp_next)
        print(dp_len)        
        return mav_val
    

solution = Solution()
nums = [1,3,6,7,9,4,10,5,6]
print(solution.lengthOfLIS(nums))
    