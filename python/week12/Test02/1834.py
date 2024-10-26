import heapq

class Solution:
    def getOrder(self, tasks: list[list[int]]) -> list[int]:
        for i in range (len(tasks)) :
            tasks[i].append(i)
        tasks = sorted(tasks, key=lambda x: x[0])
        # tasks.sort()
        ret = []
        
        now = 1
        que = []
        cursor = 0
        count = len(tasks)
        while(count > 0) :
        
            for i in range (cursor, len(tasks)) :
                if tasks[i][0] <= now :
                    heapq.heappush(que, (tasks[i][1], tasks[i][2], tasks[i][0]))
                    cursor += 1
                else :
                    break
            
            if not que :
                now = tasks[cursor][0]
                continue
                        
            curr = heapq.heappop(que)
            now += curr[0]
            ret.append(curr[1])
            count -= 1

        return ret
    
solution = Solution()
# tasks = [[1,2],[2,4],[3,2],[4,1]]
# tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
tasks = [[5,2],[7,2],[9,4],[6,3],[5,10],[1,1]]
print(solution.getOrder(tasks))