import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        
        Arrays.sort(targets, Comparator.comparingInt((int[] o) -> o[1])
                   .thenComparingInt(o -> o[0]));
        
        int idx = 0;
        boolean[] busted = new boolean[targets.length]; 
        
        for(int i = 0; i < targets.length; i++) {
            if (busted[i]) continue;
            busted[i] = true;
            answer++;
            
            int attackStart = targets[i][1] - 1;
            int attackEnd = targets[i][1];
            
            for(int j = i+1; j < targets.length; j++) {
                
                if(targets[j][1] >= attackEnd) {
                    if(targets[j][0] <= attackStart) busted[j] = true; // 요격지점이랑 미사일이 겹친경우
                    else if (targets[j][0] >= attackEnd) break; // 요격지점보다 뒤에 있는 경우
                }
            }
        }
        
        return answer;
    }
}