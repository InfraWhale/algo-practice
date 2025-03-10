import java.util.*;

class Solution {
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];
        
        Map<String, Integer> moneyMap = new HashMap<>();
        Map<String, String> referMap = new HashMap<>();
        
        for(int i=0; i<enroll.length; i++) {
            moneyMap.put(enroll[i], i);
            referMap.put(enroll[i], referral[i]);
        }
        
        for(int i=0; i<seller.length; i++) {
            String nowSeller = seller[i];
            int money = amount[i] * 100;
            while(!nowSeller.equals("-") && money > 0) { // 돈이 남지 않으면 탐색 중단 추가
                int fee = money / 10;
                answer[moneyMap.get(nowSeller)] += (money - fee);
                money = fee;
                nowSeller = referMap.get(nowSeller);
            }
        }
                
        return answer;
    }
}