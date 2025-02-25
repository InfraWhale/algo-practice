// 못 품

import java.util.*;

class Solution {    
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        String answer = "";
        
        int move = Math.abs(r-x) + Math.abs(c-y);
        if(k < move || ((k-move) % 2 == 1)) return "impossible";
        
        if(r > x) {
            answer = addString(r-x, answer, "d");
            x = r;
        }

        // du도 고려
        
        if(c < y) {
            answer = addString(y-c, answer, "l");
            y = c;
        }
        
        if(y != 1) {
            answer = addString((k-move) / 2, answer, "lr");
        } else {
            answer = addString((k-move) / 2, answer, "rl");
        }
        
        if(c > y) {
            answer = addString(c-y, answer, "r");
            y = c;
        }
        
        if(r < x) {
            answer = addString(x-r, answer, "u");
            x = r;
        }
        
        return answer;
    }
    
    public String addString(int count, String original, String additional) {
        StringBuilder sb = new StringBuilder();
        sb.append(original);
        for(int i = 0; i < count; i++) {
            sb.append(additional);
        }
        return sb.toString();
    }
}