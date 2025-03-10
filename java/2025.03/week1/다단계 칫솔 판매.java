// 채점 결과
// 정확성: 76.9
// 합계: 76.9 / 100.0
// 시간 초과

import java.util.*;

class Solution {
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];
        
        Map<String, Integer> moneyMap = new HashMap<>();
        Map<String, String> referMap = new HashMap<>();
        
        for(int i=0; i<enroll.length; i++) {
            moneyMap.put(enroll[i], 0);
            referMap.put(enroll[i], referral[i]);
        }
        
        for(int i=0; i<seller.length; i++) {
            String nowSeller = seller[i];
            int money = amount[i] * 100;
            while(!nowSeller.equals("-")) {
                int fee = money / 10;
                moneyMap.put(nowSeller, moneyMap.get(nowSeller) + money - fee);
                money = fee;
                nowSeller = referMap.get(nowSeller);
            }
        }
        
        for(int i=0; i<enroll.length; i++) {
            answer[i] = moneyMap.get(enroll[i]);
        }
        
        return answer;
    }
}