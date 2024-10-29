class Solution:
    def numSpecial(self, mat: list[list[int]]) -> int:
        arr = []
        
        for i in range (len(mat)) :
            for j in range (len(mat[0])) :
                if mat[i][j] == 1 :
                    arr.append((i, j))
                    
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
        return cnt
    
solution = Solution()
mat = [[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,1],[0,0,0,0,1,0,0,0],[1,0,0,0,1,0,0,0],[0,0,1,1,0,0,0,0]]
print(solution.numSpecial(mat))

#https://leetcode.com/submissions/detail/1435718207/