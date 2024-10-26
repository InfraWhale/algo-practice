class Solution:
    def predictTheWinner(self, nums: list[int]) -> bool:
        ln_nums = len(nums)
        sum = 0
        for no in nums :
            sum += no
            
        # print(sum)
        
        global one_score
        global two_score
        global flag
        
        one_score = 0
        two_score = 0
        flag = False
        
        def game(start, end, count) :
            print("game : ", start, end, count)
            global one_score
            global two_score
            global flag
            if count > ln_nums :
                return
            
            if count % 2 == 1 : # 홀수 : 첫번째 플레이어 차례
                one_score += nums[start]
                if one_score >= sum / 2 :
                    print("aaa")
                    flag = True
                    one_score -= nums[start]
                    return
                game (start+1, end, count+1)
                one_score -= nums[start]
                
                one_score += nums[end]
                if one_score >= sum / 2 :
                    print("bbb")
                    flag = True
                    one_score -= nums[end]
                    return
                game (start, end-1, count+1)
                one_score -= nums[end]
            else :
                two_score += nums[start]
                if two_score > sum / 2 :
                    two_score -= nums[start]
                    return
                game (start+1, end, count+1)
                two_score -= nums[start]
                
                two_score += nums[end]
                if two_score > sum / 2 :
                    two_score -= nums[end]
                    return
                game (start, end-1, count+1)
                two_score -= nums[end]
            return
        
        game(0, ln_nums-1, 1)
        
        return flag

solution = Solution()
nums = [1,5,2]
print(solution.predictTheWinner(nums))
    