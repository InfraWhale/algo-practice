import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        
        Map<String, Integer[]> map = new HashMap<>();
        
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();
        
        char[] charArr1 = str1.toCharArray();
        char[] charArr2 = str2.toCharArray();
        
        for(int i = 0; i < charArr1.length - 1; i++) {
            char char1 = charArr1[i];
            char char2 = charArr1[i+1];
            if(char1 >= 'a' && char1 <= 'z' && char2 >= 'a' && char2 <='z') {
                String temp = "" + char1 + char2;
                if(map.containsKey(temp)) {
                    Integer[] elem = map.get(temp);
                    elem[0]++;
                } else {
                    map.put(temp, new Integer[] {1, 0});
                }
            }
        }
        
        for(int i = 0; i < charArr2.length - 1; i++) {
            char char1 = charArr2[i];
            char char2 = charArr2[i+1];
            if(char1 >= 'a' && char1 <= 'z' && char2 >= 'a' && char2 <='z') {
                String temp = "" + char1 + char2;
                if(map.containsKey(temp)) {
                    Integer[] elem = map.get(temp);
                    elem[1]++;
                } else {
                    map.put(temp, new Integer[] {0, 1});
                }
            }
        }
        
        int minVal = 0;
        int maxVal = 0;
        
        for (Map.Entry<String, Integer[]> entry : map.entrySet()) {
            minVal += Math.min(entry.getValue()[0], entry.getValue()[1]);
            maxVal += Math.max(entry.getValue()[0], entry.getValue()[1]);
        }
        
        if (maxVal == 0) return 65536;
        
        return 65536 * minVal / maxVal;
    }
}