class Solution:
    def trap(self, height: list[int]) -> int:
        if not height:
            return 0

        stack = []  # 스택은 인덱스를 저장
        water_trapped = 0

        for i in range(len(height)):
            # 스택에 있는 값보다 현재 높이가 높은 경우 물이 고일 수 있는 영역 계산
            while stack and height[i] > height[stack[-1]]:
                bottom_idx = stack.pop()

                # 스택이 비었다면 왼쪽 벽이 없으므로 물을 고를 수 없는 구간
                if not stack:
                    break
                
                left_idx = stack[-1]
                # 현재 인덱스(i)와 left_idx 사이에 물이 고일 수 있는 너비
                distance = i - left_idx - 1
                # 높이는 현재 높이와 left 높이 중 작은 높이에서 bottom 높이를 빼서 구함
                bounded_height = min(height[i], height[left_idx]) - height[bottom_idx]
                
                water_trapped += distance * bounded_height

            # 현재 인덱스 스택에 추가
            stack.append(i)

        return water_trapped

solution = Solution()
height = [0,1,0,2,1,0,1,3,2,1,2,1]
print(solution.trap(height))
    