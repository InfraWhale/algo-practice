import java.util.*;

class Solution {
    public String solution(int n, int t, int m, int p) {
        String answer = "";
        List<Integer> nowNum = new ArrayList<>();
        nowNum.add(0);
        
        int loop = 0;
        int pCnt = 0;
        while(pCnt < t) { // while문 한 번 돌때 pCnt가 여러번 커질 수 있음을 고려해야함 : 여기서 헤맴
            // 현재 숫자 탐색
            for(int i = nowNum.size()-1; i > -1; i--) {
                loop++;
                if (loop == p) {
                    answer += makeString(nowNum.get(i));
                    pCnt++;
                    if(pCnt == t) break; // pCnt 채우면 딱 끝나도록
                }
                if (loop == m) loop = 0;
            }
            // 숫자 늘리기
            int idx = 0;
            while(idx < nowNum.size()) {
                int num = nowNum.get(idx) + 1;
                if(num < n) {
                    nowNum.set(idx, num);
                    break;
                } else {
                    nowNum.set(idx++, 0);
                }
            }
            if(idx == nowNum.size()) nowNum.add(1);
        }
        
        return answer;
    }
    
    public String makeString(int num) {
        String[] ABC = {"A", "B", "C", "D", "E", "F"};
        if(num < 10) return String.valueOf(num);
        else return ABC[num-10];
    }
}
