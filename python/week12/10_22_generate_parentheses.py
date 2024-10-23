# 통과는 하는데 시간 넘 오래 걸림
class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        ret = []
        arr_arr = [[] for i in range(n)]
        arr_arr[0] = ["()"]
        for i in range (1, n) :
            for j in range (len(arr_arr[i-1])) :
                str = arr_arr[i-1][j]
                for k in range (len(str) + 1) :
                    sum_str = str[:k] + "()" + str[k:]
                    if sum_str not in arr_arr[i] :
                        arr_arr[i].append(sum_str)
        return arr_arr[n-1]

solution = Solution()
n = 3
print(solution.generateParenthesis(n))
    