class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ln = len(s)
        arr = []
        for i in range (ln) :
            if s[i] != " ":
                arr.append(i)
        if not arr :
            return 0
        cnt = 0
        
        print(arr)
        temp =[]
        while(arr) :
            cnt += 1
            print(cnt)
            for i in arr :
                if i+cnt >= ln or s[i] == s[i+cnt] :
                    temp.append(i)
            for j in temp :
                arr.remove(j)
            temp = []
            print(arr)
        return cnt

solution = Solution()
s = "abcabcbb"
print(solution.lengthOfLongestSubstring(s))
    