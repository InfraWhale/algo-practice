// 2번예제 틀림림

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = 0;
        
        int queLen = queue1.length;
                
        long queSum1 = 0;
        long queSum2 = 0;
        
        for(int i = 0; i < queLen; i++) {
            queSum1 += queue1[i];
            queSum2 += queue2[i];
        }
        
        if((queSum1 + queSum2) % 2 == 1) return -1;
        long goal = (queSum1 + queSum2) / 2 - queSum1;
        
        int idx1 = 0;
        int idx2 = 0;
        
        while(goal != 0) {
            answer++;
            if(goal > 0) { // queue2가 더 크다
                if(idx2 == queLen) break;
                System.out.println("case2 " + queue2[idx2]);
                goal -= queue2[idx2++];
            } else { // queue1이 더 크다
                if(idx1 == queLen) break;
                System.out.println("case1 " + queue1[idx1]);
                goal += queue1[idx1++];
            }
        }
        System.out.println("goal : " + goal);
        return goal == 0 ? answer : -1;
    }
}