class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals.sort()
        ret = [intervals[0]]
        for i in range(1, len(intervals)) :
            new_inter = intervals[i]
            if ret[-1][1] >= new_inter[0] :
                new_inter = [min(ret[-1][0], new_inter[0]), max(ret[-1][1], new_inter[1])]
                ret.pop()
            ret.append(new_inter)
                
        return ret

solution = Solution()
intervals = [[1,4],[4,5]]
print(solution.merge(intervals))
    