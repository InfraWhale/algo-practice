// 채점 결과
// 정확성: 15.0
// 합계: 15.0 / 100.0
// 좀만 수정하면 될수도?

import java.util.*;

class Solution {
    static int [] mentorNum;
    static int [] maxMentorNum;
    static int mentorCount;
    static int[][] sReqs;
    static PriorityQueue<Integer> [] mentorLine;
    static int minVal = 987654321;
    
    public int solution(int k, int n, int[][] reqs) {
        
        mentorNum = new int [k + 1];
        maxMentorNum = new int [k + 1];
        mentorLine = new PriorityQueue [k + 1];
        
        mentorCount = k;
        sReqs = reqs;
        
        Arrays.fill(mentorNum, 1);
        
        for(int i = 0; i < reqs.length; i++) {
            maxMentorNum[reqs[i][2]]++;
        }
        
        for(int i = 0; i <= mentorCount; i++) {
            mentorLine[i] = new PriorityQueue<>();
        }
        
        findP(mentorCount, n);
        
        return minVal;
    }
    
    public void findP(int now, int goal) {
        if (now == goal) {
            calculateMin();
            return;
        }
        for (int i = 1; i <= mentorCount; i++) {
            if (mentorNum[i] + 1 > maxMentorNum[i]) continue;
            
            mentorNum[i]++;
            findP(now+1, goal);
            mentorNum[i]--;
        }
        return;
    }
    
    public void calculateMin() {
        for(int i = 0; i <= mentorCount; i++) {
            mentorLine[i].clear();
        }
        
        int delay = 0;
        for(int i = 0; i < sReqs.length; i++) {
            int idx = sReqs[i][2];
            int startTime = sReqs[i][0];
            int endTime = sReqs[i][0] + sReqs[i][1];
            
            if (mentorLine[idx].size() >= mentorNum[idx]) {
                int prevEndTime = mentorLine[idx].poll();
                if(prevEndTime > startTime) delay += (prevEndTime - startTime);
            }
            mentorLine[idx].offer(endTime);
        }
        
        minVal = Math.min(delay, minVal);
        return;
    }
}