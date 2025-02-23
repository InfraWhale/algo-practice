import java.util.*;

class Solution {
    public int solution(String[][] book_time) {
        int answer = 0;
        
        int[][] bookMin = new int[book_time.length][2];
        
        for(int i = 0; i < book_time.length; i++){
            String startTime = book_time[i][0];
            String endTime = book_time[i][1];
            bookMin[i][0] = (Integer.parseInt(startTime.substring(0, 2))) * 60 + Integer.parseInt(startTime.substring(3, 5));
            bookMin[i][1] = (Integer.parseInt(endTime.substring(0, 2))) * 60 + Integer.parseInt(endTime.substring(3, 5)) + 10;
        }
        
        Arrays.sort(bookMin, Comparator.comparingInt((int[] o) -> o[1])
                                                       .thenComparingInt(o -> o[0]));
        
        for(int i = 0; i < bookMin.length; i++){
            int endMin = bookMin[i][1];
            int count = 1;
            for(int j = i+1; j < bookMin.length; j++) {
                int nextStartMin = bookMin[j][0];
                int nextEndMin = bookMin[j][1];
                if(nextStartMin < endMin) count++;
            }
            answer = Math.max(answer, count);
        }
        
        return answer;
    }
}