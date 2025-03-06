// 채점 결과
// 정확성: 35.7
// 합계: 35.7 / 100.0

import java.util.*;

class Solution {
    int[] answer = new int[11];
    int[] tempAnswer = new int[11];
    int[] sInfo;
    int maxScore = 0;
    boolean flag = false;
    
    public int[] solution(int n, int[] info) {
        sInfo = info;
        
        backtrack(0, 0, 0, n);
        
        int [] wrong = {-1};
        
        return flag ? answer : wrong;
    }
    
    void backtrack(int depth, int apeach, int lion, int arrow) {
        if(depth == 11) {
            if(arrow > 0) tempAnswer[10] += arrow;
            if(apeach < lion) {
                if(maxScore < lion) {
                    flag = true;
                    answer = Arrays.copyOf(tempAnswer, 11);
                    maxScore = lion;
                } else if(maxScore == lion) {
                    for(int i = 10; i > -1; i--) {
                        if(tempAnswer[i] == answer[i]) continue;
                        if(tempAnswer[i] > answer[i]) answer = Arrays.copyOf(tempAnswer, 11);
                        break;
                    }
                }
            }
            tempAnswer[10] = 0;
            return;
        }
        int score = 10-depth;
        // 라이언이 이기는 경우
        if(arrow > sInfo[depth]) {
            tempAnswer[depth] = sInfo[depth]+1;
            backtrack(depth+1, apeach, lion+score, arrow - (sInfo[depth]+1));
            tempAnswer[depth] = 0;
        }
        
        // 비기는 경우
        if(arrow >= sInfo[depth]) {
            tempAnswer[depth] = sInfo[depth];
            backtrack(depth+1, apeach, lion, arrow - sInfo[depth]);
            tempAnswer[depth] = 0;
        }
        
        // 어피치가 이기는 경우
        if(sInfo[depth] > 0) {
            backtrack(depth+1, apeach+score, lion, arrow);
        }
        return;
    }
}