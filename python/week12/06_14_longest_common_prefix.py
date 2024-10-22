class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        ret = ""
        cnt = 200
        flag = False
        for i in range (len(strs)) :
            cnt = min(len(strs[i]), cnt)
        

        for i in range (cnt) :
            char = strs[0][i]
            for j in range (1, len(strs)) :
                if strs[j][i] != char :
                    flag = True
                    break
            if flag :
                break
            ret += char
        return ret
    
    strs = ["flower","flow","flight"]
    

solution = Solution()
strs = ["flower", "flow", "flight"]
print(solution.longestCommonPrefix(strs))
    