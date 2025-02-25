import java.util.*;

class Solution {
    public int[] solution(int e, int[] starts) {
        int[] answer = new int[starts.length];
        
        int[] count = new int[e+1];
        
        for(int i = 1; i <= (int) Math.sqrt(e); i++) {
            int num = (int) Math.pow(i, 2);
            count[num] += 1;
            num += i;
            while(num <= e) {
                count[num] += 2;
                num += i;
            }
        }
        
        //System.out.println(Arrays.toString(count));
        
        int[] dp = new int[e+1]; // e ~ s 역순범위에서 가장 많이 나온 수
        dp[e] = e;
        int pos = e; // 탐색완료된 지점
        
        for(int i = 0; i < starts.length; i++) {
            int s = starts[i];
            if(s < pos) {
                for(int j = pos-1; j >= s; j--) {
                    if(count[j] >= count[dp[j+1]]) dp[j] = j;
                    else dp[j] = dp[j+1];
                }
                pos = s;
            }
            answer[i] = dp[s];
        }
        //System.out.println(Arrays.toString(dp));
        
        return answer;
    }
}