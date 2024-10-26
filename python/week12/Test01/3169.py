class Solution:
    def countDays(self, days: int, meetings: list[list[int]]) -> int:
        cnt = days
        meetings.sort()
        mg = [meetings[0]]
        for i in range(1, len(meetings)) :
            new_mt = meetings[i]
            if mg[-1][1] >= new_mt[0] :
                new_mt = [min(mg[-1][0], new_mt[0]), max(mg[-1][1], new_mt[1])]
                mg.pop()
            mg.append(new_mt)
        
        for i in range(len(mg)) :
            cnt -= (mg[i][1] - mg[i][0] + 1)
        return cnt
            

solution = Solution()
days = 10
meetings = [[5,7],[1,3],[9,10]]
print(solution.countDays(days, meetings))

# https://leetcode.com/submissions/detail/1431975502/