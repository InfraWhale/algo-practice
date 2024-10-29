class Solution:
    def trap(self, height: list[int]) -> int:
        
        max_height = max(height)
        max_idxs = [idx for idx, val in enumerate(height) if val == max_height]
        
        if max_height == 0 :
            return 0
        
        vol = 0
        
        start_idx = 0
        end_idx = len(height)-1
        for i in range (len(height)) :
            if height[i] > 0 :
                start_idx = i
                break
        for i in range (len(height)-1, -1, -1) :
            if height[i] > 0 :
                end_idx = i
                break
        
        for i in range (start_idx+1, max_idxs[0]+1) :
            if height[i] >= height[start_idx] :
                for j in range (start_idx+1, i) :
                    vol += (height[start_idx] - height[j])
                start_idx = i
                
        for i in range (end_idx-1, max_idxs[-1]-1, -1) :
            if height[i] >= height[end_idx] :
                for j in range (i+1, end_idx) :
                    vol += (height[end_idx] - height[j])
                end_idx = i
                
        for i in range (max_idxs[0]+1, max_idxs[-1]) :
            vol += (max_height - height[i])
                
        return vol

solution = Solution()
height = [0,1,0,2,1,0,1,3,2,1,2,1]
print(solution.trap(height))
    