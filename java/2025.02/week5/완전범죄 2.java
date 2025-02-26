// 채점 결과
// 정확성: 55.0
// 합계: 55.0 / 100.0

import java.util.*;

class Solution {
    public int solution(int[][] info, int n, int m) {
        int answer = 0;
        
        int infoLength = info.length;
        boolean[] visited = new boolean[infoLength];
        
        Arrays.sort(info, Comparator.comparingInt((int[] o) -> o[0]).reversed()
           .thenComparingInt(o -> o[1]));
        
        int aCount = 0;
        int bCount = 0;
        int totalSteal = 0;
        for(int i = 0; i < infoLength; i++) {
            if(bCount+info[i][1] < m) {
                visited[i] = true;
                bCount += info[i][1];
                totalSteal++;
            }
        }
        
        for(int i = 0; i < infoLength; i++) {
            if(visited[i]) continue;
            if(aCount+info[i][0] < n) {
                aCount += info[i][0];
                totalSteal++;
            }
        }
        
        answer = (totalSteal == infoLength) ? aCount : -1;
        
        return answer;
    }    
}