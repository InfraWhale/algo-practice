class Solution:
    def minTimeToVisitAllPoints(self, points: list[list[int]]) -> int:
        ret = 0
        
        for i in range (len(points)-1) :
            now_x = points[i][0]
            now_y = points[i][1]
            
            des_x = points[i+1][0]
            des_y = points[i+1][1]
            
            while (now_x != des_x or now_y != des_y) :
                if now_x > des_x :
                    now_x -= 1
                elif now_x < des_x :
                    now_x += 1
                
                if now_y > des_y :
                    now_y -= 1
                elif now_y < des_y :
                    now_y += 1
                    
                ret += 1
        return ret
    
solution = Solution()
points = [[3,2],[-2,2]]
print(solution.minTimeToVisitAllPoints(points))

#https://leetcode.com/submissions/detail/1432941078/