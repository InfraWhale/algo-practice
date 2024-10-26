class Solution:
    def calcEquation(self, equations: list[list[str]], values: list[float], queries: list[list[str]]) -> list[float]:
        for i in range (len(equations)) :
            equations.append([equations[i][1], equations[i][0]])
            values.append(1 / values[i])
            
        visited = []
        global ret
        ret = -1.0
        
        def dfs (start : str, end : str, ans : float) :
            global ret
            
            for i in range (len(equations)) :
                if equations[i][0] != start :
                    continue
                
                if start == end :
                    ret = ans
                    return
                
                if equations[i][1] in visited :
                    continue
                
                new_ans = ans * values[i]
                visited.append(equations[i][1])
                
                if equations[i][1] == end :
                    ret = new_ans
                    return
                
                dfs(equations[i][1], end, new_ans)
                visited.remove(equations[i][1])
                    
            return
        
        ret_arr = []
        for query in queries :
            visited = []
            ret = -1.0
            visited.append(query[0])
            dfs(query[0], query[1], 1)
            ret_arr.append(ret)
                
        return ret_arr
        
solution = Solution()
equations = [["a","b"],["b","c"]]
values = [2.0,3.0]
queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
print(solution.calcEquation(equations, values, queries))
    