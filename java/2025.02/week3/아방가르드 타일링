// 채점 결과
// 정확성: 6.7
// 합계: 6.7 / 100.0
// 접근 방식은 맞는 것 같은데 ... 다시 풀것

class Solution {
    public int solution(int n) {
        int answer = 0;
        
        int dp[] = new int [100000+1];
        int unique[] = new int [100000+1];
        
        unique[1] = 1;
        unique[2] = 2;
        unique[3] = 5;
        
        for(int i = 4; i <= n; i++) {
            if(i % 3 == 0) unique[i] = 4;
            else unique[i] = 2;
        }
        
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            long temp = 0;
            for(int j = i; j >= 1; j--) {
                temp += unique[j]*dp[i-j]%1000000007;
            }
            temp %= 1000000007;
            dp[i] = (int) temp;
            //System.out.println(dp[i]);
        }

        return dp[n];
    }
}