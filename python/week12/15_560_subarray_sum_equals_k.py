class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        pres_arr = {}
        
        num = 0
        ret = 0
        for i in range (len(nums)) :
            num += nums[i]
            
            if num-k == 0 :
                ret += 1
            if num-k in pres_arr :
                ret += pres_arr[num-k]
            pres_arr[num] = pres_arr.get(num, 0) + 1

        return ret
        
solution = Solution()
nums = [1,1,1]
k = 2
print(solution.subarraySum(nums, k))
    