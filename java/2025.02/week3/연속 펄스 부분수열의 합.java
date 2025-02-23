import java.util.*;

class Solution {
    public long solution(int[] sequence) {
        long answer = -987654321;
        
        int sequenceLength = sequence.length;
        
        long [][] dp = new long [sequenceLength][sequenceLength+1]; // 시작 인덱스 & 길이
        
        for(int i = 0; i < sequenceLength; i++) {
            dp[i][1] = Math.abs(sequence[i]);
            answer = Math.max(answer, dp[i][1]);
        }
        
        for(int size = 2; size <= sequenceLength; size++) {
            for(int startIdx = 0; startIdx < sequenceLength; startIdx++) {
                if(startIdx+size <= sequenceLength) {
                    dp[startIdx][size] = Math.abs(dp[startIdx][size-1] - sequence[startIdx+size-1]);
                    answer = Math.max(answer, dp[startIdx][size]);
                }
            }
        }
        return answer;
    }
}