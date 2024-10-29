class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        cnt_server = 0
        
        arr = []
        
        for i in range (len(grid)) :
            for j in range (len(grid[0])) :
                if grid[i][j] == 1 :
                    arr.append((i, j))
                    cnt_server += 1
                    
        valid = [1 for _ in range(len(arr))]
        
        for i in range (len(arr)) :
            for j in range (i+1, len(arr)) :
                if arr[i][0] == arr[j][0] or arr[i][1] == arr[j][1] :
                    valid[i] = 0
                    valid[j] = 0
        cnt = 0
        for i in valid :
            if i == 1 :
                cnt += 1
        return cnt_server - cnt
    
solution = Solution()
grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
print(solution.countServers(grid))

#https://leetcode.com/submissions/detail/1435732634/