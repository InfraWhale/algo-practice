import java.util.*;

class Solution {
    
    int orderlen, goal;
    String nowOrder;
    Map<String, Integer> map = new HashMap<>();
    int[] maxCount = new int[11];
    
    public String[] solution(String[] orders, int[] course) {
        for(String order : orders) {
            // 오름차순 정렬
            char[] charArray = order.toCharArray();
            Arrays.sort(charArray);
            nowOrder = new String(charArray);
            orderlen = order.length();
            
            StringBuilder sb = new StringBuilder("");
            for(int i = 0; i < course.length; i++) {
                goal = course[i];
                makeOrder(0, 0, sb);
            }
        }
        
        List<String> list = new ArrayList<>();
        
        for(Map.Entry<String, Integer> entry : map.entrySet()) {
            int keyLen = entry.getKey().length();
            if(entry.getValue() > 1 && entry.getValue() == maxCount[keyLen]) list.add(entry.getKey());
        }
        
        String[] answer = list.toArray(new String[0]);
        Arrays.sort(answer);
        return answer;
    }
    
    public void makeOrder(int pos, int len, StringBuilder madeCourse) {
        if(len == goal) {
            String temp = madeCourse.toString();
            map.put(temp, map.getOrDefault(temp, 0) + 1);
            maxCount[len] = Math.max(map.get(temp), maxCount[len]);
            return;
        }    
            
        for(int i = pos; i < orderlen; i++) {
            madeCourse.append(nowOrder.charAt(i));
            makeOrder(i+1, len+1, madeCourse);
            madeCourse.deleteCharAt(len);
        }
        return;
    }
}