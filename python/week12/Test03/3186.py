# 못품
class Solution:
    def maximumTotalDamage(self, power: list[int]) -> int:
        dic = {}
        
        for i in power :
            dic[i] = dic.get(i, 0) + 1
        # print (dic)
        
        new_dic = sorted(dic)
        # print (new_dic)
        
        global max_val
        max_val = 0
        def get_dmg(idx, sum) :
            global max_val
            for next_idx in range (idx+1, len(new_dic)) :
                if new_dic[next_idx] <= new_dic[idx] + 2 :
                    continue
                new_sum = sum + new_dic[next_idx] * dic[new_dic[next_idx]]
                max_val = max(max_val, new_sum)
                # print("max_val : ", max_val)
                get_dmg(next_idx, new_sum)
            return
        
        for i in range (len(new_dic)) :
            now_sum = new_dic[i] * dic[new_dic[i]]
            max_val = max(max_val, now_sum)
            get_dmg(i, now_sum)
                
        return max_val
    
solution = Solution()
power = [7,1,6,6]
print(solution.maximumTotalDamage(power))