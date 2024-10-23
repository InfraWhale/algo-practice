# 답봄

class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        ret = []
        nums.sort()

        for left in range (len(nums)-2) :
            if left > 0 and nums[left] == nums[left - 1]:
                continue
            
            mid = left + 1
            right = len(nums)-1

            while (mid < right) :
                sum = nums[left] + nums[mid] + nums[right]
                if sum == 0 :
                    ret.append([nums[left], nums[mid], nums[right]])

                    while mid < right and nums[mid] == nums[mid + 1]:
                        mid += 1
                    while mid < right and nums[right] == nums[right - 1]:
                        right -= 1
                    
                    mid += 1
                    right -= 1
                elif sum < 0:
                    mid += 1
                else:
                    right -= 1
        return ret
    
solution = Solution()
nums = [-1,0,1,2,-1,-4]
print(solution.threeSum(nums))