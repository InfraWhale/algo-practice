import heapq

class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        max_heap = []
        for no in nums :
            heapq.heappush(max_heap, -no)
        
        for i in range (k) :
            ret = heapq.heappop(max_heap)
        return -ret
        
solution = Solution()
nums = [3,2,1,5,6,4]
k = 2
print(solution.findKthLargest(nums, k))
    