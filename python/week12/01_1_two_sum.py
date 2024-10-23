class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i in range (len(nums)):
            for j in range (len(nums)):
                if i == j :
                    continue
                if nums[i] + nums[j] == target :
                    ret = []
                    ret.append(i)
                    ret.append(j)
                    return ret
    
solution = Solution()
nums = [2,7,11,15]
target = 9
print(solution.twoSum(nums, target))