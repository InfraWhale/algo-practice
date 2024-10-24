class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        start = 0
        end = len(nums) - 1
        mid = (start+end) // 2
        flag = False
        while (start <= end) :
            mid = (start+end) // 2
            if nums[mid] == target :
                flag = True
                break
            elif nums[mid] < target :
                start = mid+1
            else :
                end = mid-1
        if not flag :
            return [-1, -1]
        
        min_val = mid
        max_val = mid
        
        while (min_val > 0 and nums[min_val-1] == target) :
            min_val -= 1
        
        while (max_val < len(nums) -1 and nums[max_val+1] == target) :
            max_val += 1
                
        return [min_val, max_val]
        
solution = Solution()
nums = [5,7,7,8,8,10]
target = 8
print(solution.searchRange(nums, target))
    