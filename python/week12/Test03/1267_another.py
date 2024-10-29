class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        
        rows = len(grid)
        cols = len(grid[0])
        
        row_sum = [sum(row) for row in grid]
        col_sum = [sum(grid[i][j] for i in range(rows)) for j in range(cols)]
        
        cnt_server = sum(row_sum)
        
        count = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1 and row_sum[i] == 1 and col_sum[j] == 1:
                    count += 1
        
        return cnt_server - count
    
solution = Solution()
grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
print(solution.countServers(grid))

#https://leetcode.com/submissions/detail/1435732634/