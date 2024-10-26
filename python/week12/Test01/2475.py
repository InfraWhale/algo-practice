class Solution:
    def unequalTriplets(self, nums: list[int]) -> int:
        ret = 0
        
        for i in range (len(nums)) :
            for j in range (i+1, len(nums)) :
                if nums[j] == nums[i] :
                    continue
                for k in range (j+1, len(nums)) :
                    if nums[k] != nums[i] and nums[k] != nums[j]:
                        ret += 1
        return ret
    
solution = Solution()
nums = [4,4,2,4,3]
print(solution.unequalTriplets(nums))

#https://leetcode.com/submissions/detail/1431961492/