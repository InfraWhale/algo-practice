import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        int answer = 0;
        
        int friendLen = friends.length;
        int[][] friendReaction = new int[friendLen][friendLen]; // 선물 주고받은 기록
        
        Map<String, Integer> friendIdx = new HashMap<>(); // 이름별 인덱스
        int idx = 0;
        for(String name : friends) {
            friendIdx.put(name, idx);
            idx++;
        }
        
        int[][] personalRecord = new int[friendLen][2]; // 선물지수, 다음달 받는 선물 수
        
        for(String names : gifts) {
            String[] fromTo = names.split(" ");
            int fromIdx = friendIdx.get(fromTo[0]);
            int toIdx = friendIdx.get(fromTo[1]);
            
            friendReaction[fromIdx][toIdx]++;
            personalRecord[fromIdx][0]++;
            personalRecord[toIdx][0]--;
        }
        
        for(int i = 0; i < friendLen; i++) {
            for(int j = i + 1; j < friendLen; j++) {
                if(friendReaction[i][j] > friendReaction[j][i]) {
                    personalRecord[i][1]++;
                } else if(friendReaction[i][j] < friendReaction[j][i]) {
                    personalRecord[j][1]++;
                } else {
                    if(personalRecord[i][0] > personalRecord[j][0]) personalRecord[i][1]++;
                    else if(personalRecord[i][0] < personalRecord[j][0]) personalRecord[j][1]++;
                }
            }
        }
        
        for(int i = 0; i < friendLen; i++) {
            answer = Math.max(personalRecord[i][1], answer);
        }
        
        return answer;
    }
}