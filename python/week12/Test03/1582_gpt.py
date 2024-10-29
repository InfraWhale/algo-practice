class Solution:
    def numSpecial(self, mat: list[list[int]]) -> int:
        rows = len(mat)
        cols = len(mat[0])
        
        # 각 행과 열에 있는 1의 개수를 미리 계산
        row_sum = [sum(row) for row in mat]
        col_sum = [sum(mat[i][j] for i in range(rows)) for j in range(cols)]
        
        # 각 위치가 "특수한 위치"인지 확인
        count = 0
        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 1 and row_sum[i] == 1 and col_sum[j] == 1:
                    count += 1
                    
        return count
    
solution = Solution()
mat = [[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,1],[0,0,0,0,1,0,0,0],[1,0,0,0,1,0,0,0],[0,0,1,1,0,0,0,0]]
print(solution.numSpecial(mat))

#https://leetcode.com/submissions/detail/1435718207/