// 채점 결과
// 정확성: 44.1
// 합계: 44.1 / 100.0

class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {};
        
        int sequenceLen = sequence.length;
        
        int [][] dp = new int [sequenceLen+1][sequenceLen+1];
        
        for(int i = 0; i < sequenceLen; i++) {
            if(sequence[i] > k) {
                sequenceLen = i;
                break;
            }
            dp[i][i] = sequence[i];
            if(dp[i][i] == k) return new int[] {i, i};
        }
        
        for(int len = 1; len < sequenceLen; len++) {
            for(int i = 0; i < sequenceLen-len; i++) {
                dp[i][i+len] = dp[i][i+len-1] + sequence[i+len];
                if(dp[i][i+len] > k) break;
                if(dp[i][i+len] == k) return new int[] {i, i+len};
            }
        }
        
        return answer;
    }
}