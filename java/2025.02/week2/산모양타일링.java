// 2024 카카오 인턴 5번
// 답 보고 품

class Solution {
    
    static int[][] dp;
    
    public int solution(int n, int[] tops) {
        int answer = 0;
        
        dp = new int[n][2];
        
        // 다음 공간을 침범하지 않음
        if(tops[0] == 1) dp[0][0] = 3;
        else dp[0][0] = 2;
        
        // 다음 공간을 침범
        dp[0][1] = 1; 
        
        if (n == 1) {
            return dp[0][0] + dp[0][1];
        }
        
        for (int i = 1; i < n; i++) {
            if(tops[i] == 0) dp[i][0] = (dp[i-1][0] * 2 + dp[i-1][1]) % 10007;
            else dp[i][0] = (dp[i-1][0] * 3 + dp[i-1][1] * 2) % 10007;
            dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % 10007;;
        }
        
        answer = (dp[n-1][0] + dp[n-1][1]) % 10007;
        
        return answer;
    }
}