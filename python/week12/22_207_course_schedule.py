#위상 정렬 -> 이론 다시 봄
from collections import deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        
        indegree = [0 for _ in range (numCourses)]
        graph = [[] for _ in range (numCourses)]
        
        for pre in prerequisites :
            graph[pre[1]].append(pre[0])
            indegree[pre[0]] += 1
        
        def check_no_cycle() :
            q = deque()
            for i in range (numCourses) :
                if indegree[i] == 0 :
                    q.append(i)
                        
            count = 0
            while count < numCourses:
                if not q :
                    return False
                
                now = q.popleft()
                count += 1
                
                for g in graph[now] :
                    indegree[g] -= 1
                    if indegree[g] == 0:
                        q.append(g)    
            return True
        
        return check_no_cycle()

solution = Solution()
numCourses = 2
prerequisites = [[1,0]]
# prerequisites = [[1,0],[0,1]]
print(solution.canFinish(numCourses, prerequisites))
    