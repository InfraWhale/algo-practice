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
            tempAnswer[10] += arrow;
            if(apeach < lion) {
                flag = true;
                if(maxScore < lion - apeach) {
                    answer = Arrays.copyOf(tempAnswer, 11);
                    maxScore = lion - apeach;
                } else if(maxScore == lion - apeach) {
                    for(int i = 10; i >= 0; i--) {
                        if(tempAnswer[i] > answer[i]) {
                            answer = Arrays.copyOf(tempAnswer, 11);
                            break;
                        }
                        if(tempAnswer[i] < answer[i]) break;
                    }
                }
            }
            tempAnswer[10] -= arrow;
            return;
        }
        int score = 10-depth;
        // 라이언이 이기는 경우
        if(arrow > sInfo[depth]) {
            tempAnswer[depth] = sInfo[depth]+1;
            backtrack(depth+1, apeach, lion+score, arrow - (sInfo[depth]+1));
            tempAnswer[depth] = 0;
        }
        
        // 이기지 않는 경우 -> 비겨도 어피치가 점수 먹는다.
        backtrack(depth + 1, apeach + (sInfo[depth] > 0 ? score : 0), lion, arrow);
        return;
    }
}