# gpt 답안
class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        ln = len(nums)
        
        left = 0 
        total = 0
        min_len = ln + 1
        
        for right in range(ln) :
            total += nums[right]
            
            while total >= target :
                min_len = min(min_len, right - left + 1)
                total -= nums[left]
                left += 1
        
        return min_len if min_len <= ln else 0

solution = Solution()
target = 11
nums = [1,2,3,4,5]
print(solution.minSubArrayLen(target, nums))
    