class Solution {
    public int[] solution(int n, int s) {
        
        if(n > s) return new int[] {-1};
        
        int[] answer = new int [n];
        
        int divide = s / n;
        int remain = s % n;
        
        for(int i = 0; i < n-remain; i++) {
            answer[i] = divide;
        }
        
        for(int i = n-remain; i < n; i++) {
            answer[i] = divide+1;
        }
        
        return answer;
    }
}