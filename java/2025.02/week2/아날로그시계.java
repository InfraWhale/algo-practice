// 답 봄

class Solution {
    public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
        
        int start = toSecond(h1, m1, s1);
        int end = toSecond(h2, m2, s2);

        int answer = alarmCount(end) - alarmCount(start) + (alarmNow(start) ? 1 : 0);
        
        return answer;
    }
    
    public int toSecond(int hour, int min, int sec) {
        return hour * 60 * 60 + min * 60 + sec;
    }
    
    public int alarmCount(int second) {
        int hourAndSecond = second * (12*60-1) / (12*60*60) ; // (12*60*60)초 동안 (12*60-1)번 울림
        int minuteAndSecond = second * (60-1) / (60*60) ; // (60*60)초 동안 (60-1)번 울림
        int additional = (second >= (12*60*60) ? 2 : 1);
        return hourAndSecond + minuteAndSecond - additional;
    }
    
    public boolean alarmNow(int second) {
        if(second == 0 || second == (12*60*60)) return true;
        return false;
    }
}