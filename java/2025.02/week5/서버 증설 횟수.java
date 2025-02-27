import java.util.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        
        int playersLength = players.length;
        
        int[] server = new int [playersLength+k];
        Arrays.fill(server, m);
        
        for(int i = 0; i < playersLength; i++) {
            if(server[i] <= players[i]) {
                int nowServerCount = ((players[i] - server[i]) / m) + 1;
                int nowPlayerCount = nowServerCount * m;
                for(int j = i; j < i+k; j++) {
                    server[j] += nowPlayerCount;
                }
                answer += nowServerCount;
            }
        }
        //System.out.println(Arrays.toString(server));
        
        return answer;
    }
}