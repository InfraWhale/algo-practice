import java.util.*;

class Solution {
    public int solution(int temperature, int t1, int t2, int a, int b, int[] onboard) {
        int answer = 987654321;
        
        final int OUT_TEMP = temperature;
        final int ONBOARD_LEN = onboard.length;
        
        int minVal = temperature;
        int maxVal = temperature;
        
        int dp[][] = new int [51][ONBOARD_LEN];
        
        for(int i = 0; i < 51; i++) {
            Arrays.fill(dp[i], 987654321);
        }
        
        dp[OUT_TEMP+10][0] = 0;
        
        for(int i = 1; i < ONBOARD_LEN; i++) { // 탑승시간
            for(int j = minVal; j <= maxVal; j++) { // 탐색범위
                // 온도 상승
                if(j+1 <= 40) { 
                    if(onboard[i] == 0 || (j+1 >= t1 && j+1 <= t2)) {
                        if(OUT_TEMP < t1) dp[j+10+1][i] = Math.min(dp[j+10+1][i], dp[j+10][i-1] + a); // 전기써서 온도 상승시키는 경우
                        else dp[j+10+1][i] = Math.min(dp[j+10+1][i], dp[j+10][i-1]);
                        maxVal = Math.max(maxVal, j+1);
                    }
                }
                // 온도 유지
                if(onboard[i] == 0 || (j >= t1 && j <= t2)) {
                    if(j == OUT_TEMP) {
                        dp[j+10][i] = Math.min(dp[j+10][i], dp[j+10][i-1]);
                    } else {
                        dp[j+10][i] = Math.min(dp[j+10][i], dp[j+10][i-1] + b);
                    }
                }
                // 온도 하강
                if(j-1 >= -10) {
                    if(onboard[i] == 0 || (j-1 >= t1 && j-1 <= t2)) {
                        if(OUT_TEMP < t1) dp[j+10-1][i] = Math.min(dp[j+10-1][i], dp[j+10][i-1]); // 전기써서 온도 하강시키는 경우
                        else dp[j+10-1][i] = Math.min(dp[j+10-1][i], dp[j+10][i-1] + a);
                        minVal = Math.min(minVal, j-1);
                    }
                }
            }
        }
        
        for(int i = minVal; i <= maxVal; i++) {
            answer = Math.min(answer, dp[i+10][ONBOARD_LEN-1]);
        }
        
        return answer;
    }
}