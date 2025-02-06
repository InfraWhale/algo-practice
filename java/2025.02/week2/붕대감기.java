// PCCE 기출 1번

import java.util.*;

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = 0;
        
        int timeLimit = attacks[attacks.length-1][0];
        final int MAX_HEALTH = health;
        
        int completeTime = bandage[0];
        int healPerSec = bandage[1];
        int completeHeal = bandage[2];
        
        int continuousSuccess = 0;
        int attackPos = 0;
        for(int i = 1; i <= timeLimit; i++) {
            if(attacks[attackPos][0] == i) { // 공격당하면
                continuousSuccess = 0;
                health -= attacks[attackPos][1];
                attackPos++;
                if (health <= 0) return -1;
            } else { // 아니면
                continuousSuccess++;
                int nowHeal = healPerSec;
                if (continuousSuccess == completeTime) {
                    continuousSuccess = 0;
                    nowHeal += completeHeal;
                }
                health = Math.min(MAX_HEALTH, health + nowHeal);
                
            }
        }
        return health;
    }
}