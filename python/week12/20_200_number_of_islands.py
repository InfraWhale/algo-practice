class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        ln_y = len(grid)
        ln_x = len(grid[0])
        
        visited = [[0 for _ in range(ln_x)] for _ in range(ln_y)]
        
        dy = [-1, 0, 1, 0]
        dx = [0, 1, 0, -1]
        
        def dfs(y: int, x: int) :
            visited[y][x] = 1
            
            for i in range (4) :
                ny = y + dy[i]
                nx = x + dx[i]
                if(ny < 0 or ny >= ln_y or nx < 0 or nx >= ln_x or visited[ny][nx] == 1 or grid[ny][nx] == "0") :
                    continue
                dfs(ny, nx)
            return
        
        ret = 0
        for i in range(ln_y) :
            for j in range(ln_x) :
                if visited[i][j] == 1 or grid[i][j] == "0":
                    continue
                dfs(i, j)
                ret += 1
                
        return ret
        
solution = Solution()
grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
print(solution.numIslands(grid))
    