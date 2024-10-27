# gpt - 이진탐색 추가
class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        dp = []
        
        for num in nums:
            # 이진 탐색을 직접 구현하여 위치 찾기
            left, right = 0, len(dp)
            while left < right:
                mid = (left + right) // 2
                if dp[mid] < num:
                    left = mid + 1
                else:
                    right = mid
            
            # left가 dp의 길이와 같다면 새로운 숫자 추가
            if left == len(dp):
                dp.append(num)
            else:
                # left 위치에 값 교체 (더 작은 값으로 교체해 LIS를 유지)
                dp[left] = num
                
        return len(dp)

solution = Solution()
nums = [1,3,6,7,9,4,10,5,6]
print(solution.lengthOfLIS(nums))
    