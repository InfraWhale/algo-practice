class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        for i in range (len(s)) :
            if len(stk) == 0 :
                stk.append(s[i])
            else :
                if (stk[-1] == "(" and s[i] == ")") or (stk[-1] == "{" and s[i] == "}") or (stk[-1] == "[" and s[i] == "]"):
                    stk.pop()
                else :
                    stk.append(s[i])
        if len(stk) == 0 :
            return True
        else :
            return False

solution = Solution()
s = "(]"
print(solution.isValid(s))
    