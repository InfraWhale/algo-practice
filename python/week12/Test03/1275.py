class Solution:
    def tictactoe(self, moves: list[list[int]]) -> str:
        mat = [["" for _ in range(3)] for _ in range(3)]
        
        owner = "A"
        for i in range (len(moves)) :
            mat[moves[i][0]][moves[i][1]] = owner
            if owner == "A" :
                owner = "B"
            else :
                owner = "A"
        
        for i in range (3) :
            if mat[i][0] != "" and mat[i][0] == mat[i][1] == mat[i][2] :
                return mat[i][0]
            if mat[0][i] != "" and mat[0][i] == mat[1][i] == mat[2][i] :
                return mat[0][i]
        
        if mat[0][0] != "" and mat[0][0] == mat[1][1] == mat[2][2] :
            return mat[0][0]
        if mat[2][0] != "" and mat[2][0] == mat[1][1] == mat[0][2] :
            return mat[2][0]
        
        if len(moves) == 9 :
            return "Draw"
        return "Pending"
    
solution = Solution()
moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
print(solution.tictactoe(moves))

#https://leetcode.com/submissions/detail/1435728597/