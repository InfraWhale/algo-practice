// 채점 결과
// 정확성: 66.7
// 합계: 66.7 / 100.0
// 반례를 못찾겠다.

import java.util.*;

class Solution {
    public long solution(int w, int h) {
        long answer = w * h;
        
        int tiltFirst = h / w;
        int tiltSecond = h % w;
        
        int start = 0;
        
        int endFirst = tiltFirst;
        int endSecond = tiltSecond;
        
        for(int i = 0; i < w; i++) {
            int end = endSecond == 0 ? endFirst : endFirst + 1;
            answer -= (end - start);
            //System.out.println(answer);
            
            start = endFirst;
            endFirst += tiltFirst;
            endSecond += tiltSecond;
            if(endSecond >= w) {
                endSecond -= w;
                endFirst++;
            }
        }
        
        return answer;
    }
}