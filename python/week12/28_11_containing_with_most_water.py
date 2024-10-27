class Solution:
    def maxArea(self, height: list[int]) -> int:
        start = 0
        end = len(height) -1
        
        max_vol = 0
        
        while (start < end) :
            
            now_vol = min(height[start], height[end]) * (end-start)
            max_vol = max(max_vol ,now_vol)
            if height[start] < height[end] :
                start += 1
            else :
                end -= 1
            
        return max_vol
solution = Solution()
height = [1,8,6,2,5,4,8,3,7]
print(solution.maxArea(height))
    