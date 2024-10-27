# dp 풀이?
class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        # 초기화: 첫 번째 날을 최저가로 가정
        min_price = prices[0]
        max_profit = 0
        
        for price in prices[1:]:
            # 현재 가격과 최저가의 차이로 최대 이익 갱신
            max_profit = max(max_profit, price - min_price)
            # 현재 가격이 더 낮으면 최저가 갱신
            min_price = min(min_price, price)
        
        return max_profit

solution = Solution()
prices = [7,1,5,3,6,4]
print(solution.maxProfit(prices))
    