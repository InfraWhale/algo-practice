class Solution:
    def reverse(self, x: int) -> int:
        minus = False
        if(x < 0) :
            minus = True
            x = -x
        st = str(x)
        ln = len(st)
        new_st = ""
        for i in range (ln) :
            new_st += st[ln-1-i]
        new_x = int(new_st)
        if minus :
            new_x = -new_x
        if new_x < -(1 << 31) or new_x >= (1 << 31) :
            return 0
        return new_x
    
solution = Solution()
x = 120
print(solution.reverse(x))