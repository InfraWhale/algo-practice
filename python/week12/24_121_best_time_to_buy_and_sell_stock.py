# 품
class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        
        max_profit = 0
        min_val = float('Inf')
        max_val = 0
        for i in prices :
            if i < min_val :
                min_val = i
                max_val = i
            elif i > max_val :
                max_val = i
                max_profit = max(max_profit, max_val-min_val)
        
        return max_profit

solution = Solution()
prices = [7,1,5,3,6,4]
print(solution.maxProfit(prices))
    