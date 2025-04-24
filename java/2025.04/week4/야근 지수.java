import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        
        Arrays.sort(works);
        int end = works.length - 1;
        int start = end;
        
        while(n > 0) {
            start--;
            if(start == -1) {
                int minus = works[end];
                int count = end + 1;
                if(minus * count <= n) return 0;
                else {
                    // System.out.println(n);
                    int divide = n / count;
                    int remain = n % count;
                    for(int i = end; i > end-remain; i--) {
                        works[i] -= (divide+1);
                    }
                    for(int i = end-remain; i > -1; i--) {
                        works[i] -= divide;
                    }
                    // System.out.println(Arrays.toString(works));
                    break;
                }
            } else if (works[start] != works[end]) {
                int minus = works[end] - works[start];
                int count = end - start;
                if(minus * count <= n) {
                    for(int i = end; i > start; i--) {
                        works[i] -= minus;
                    }
                    n -= minus * count;
                    // System.out.println(Arrays.toString(works));
                } else {
                    int divide = n / count;
                    int remain = n % count;
                    for(int i = end; i > end-remain; i--) {
                        works[i] -= (divide+1);
                    }
                    for(int i = end-remain; i > start; i--) {
                        works[i] -= divide;
                    }
                    break;
                }
            }
        }
        
        // System.out.println(Arrays.toString(works));
        
        for(int work : works) {
            answer += Math.pow(work, 2);
        }
        
        return answer;
    }
}