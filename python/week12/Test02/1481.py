class Solution:
    def findLeastNumOfUniqueInts(self, arr: list[int], k: int) -> int:
        dic = {}
        
        for i in range (len(arr)) :
            if arr[i] in dic :
                dic[arr[i]] += 1
            else :
                dic[arr[i]] = 1
        dic = sorted(dic.values())
        
        count = 0
        for value in dic :
            if value <= k :
                count += 1
                k -= value
            else :
                break
            
        return len(dic) - count
    
solution = Solution()
arr = [5,5,4]
k = 1
print(solution.findLeastNumOfUniqueInts(arr, k))

# https://leetcode.com/submissions/detail/1432950224/
