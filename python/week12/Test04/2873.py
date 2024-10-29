class Solution:
    def maximumTripletValue(self, nums: list[int]) -> int:
        
        max_val = 0
        for i in range (len(nums)) :
            for j in range (i+1, len(nums)):
                if nums[i] - nums[j] < 0 :
                    continue
                for k in range (j+1, len(nums)) :
                    max_val = max(max_val, (nums[i] - nums[j])*nums[k])
        return max_val
    
solution = Solution()
nums = [12,6,1,2,7]
print(solution.maximumTripletValue(nums))

#https://leetcode.com/submissions/detail/1436776709/