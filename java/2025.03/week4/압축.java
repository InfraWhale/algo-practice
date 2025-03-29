import java.util.*;

class Solution {
    public int[] solution(String msg) {
        Map<String, Integer> map = new HashMap<>();
        for(int i = 1; i <= 26; i++) {
            map.put(String.valueOf((char)('A'+i-1)), i);
        }
        
        int idx = 27;
        String tempKey = "";
        int tempVal = 0;
        
        List<Integer> list = new ArrayList<>();
        
        for(int i = 0; i < msg.length(); i++) {
            String now = msg.substring(i, i+1);
            tempKey += now;
            if(map.containsKey(tempKey)) {
                tempVal = map.get(tempKey);
            } else {
                map.put(tempKey, idx++);
                list.add(tempVal);
                tempKey = now;
                tempVal = map.get(tempKey);
            }
        }
        list.add(tempVal);
        
        int[] answer = new int[list.size()];
        int listIdx = 0;
        for(int listInt : list) answer[listIdx++] = listInt;
        
        return answer;
    }
}