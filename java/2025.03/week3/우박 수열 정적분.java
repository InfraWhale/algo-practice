import java.util.*;

class Solution {
    public double[] solution(int k, int[][] ranges) {
        
        List<Integer> list = new ArrayList<>();
        while(k != 1) {
            list.add(k);
            if(k % 2 == 1) k = 3 * k + 1;
            else k /= 2; 
        }
        list.add(k);
        
        int n = list.size() - 1;
        System.out.println(n);
        
        double[] answer = new double[ranges.length];
        int idx = 0;
        
        for(int [] range : ranges) {
            int start = range[0];
            int end = n + range[1];
            
            if(start > end) {
                answer[idx++] = -1;
                continue;
            }
            
            double temp = 0;
            for(int i = start; i < end; i++) {
                temp += (double)(list.get(i) + list.get(i+1)) / 2;
            }
            answer[idx++] = temp;
        }
        
        return answer;
    }
}