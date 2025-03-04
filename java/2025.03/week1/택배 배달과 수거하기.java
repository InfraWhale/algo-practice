class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
        int pos = n-1;
        
        while(pos >= 0) {
            if(deliveries[pos] == 0 && pickups[pos] == 0) {
                pos--;
                continue;
            }
            int deliCnt = cap;
            for(int i = pos; i >= 0; i--) {
                if(deliveries[i] == 0) continue;
                if(deliCnt > deliveries[i]) {
                    deliCnt -= deliveries[i];
                    deliveries[i] = 0;
                } else {
                    deliveries[i] -= deliCnt;
                    break;
                }
            }
            int pickCnt = cap;
            for(int i = pos; i >= 0; i--) {
                if(pickups[i] == 0) continue;
                if(pickCnt > pickups[i]) {
                    pickCnt -= pickups[i];
                    pickups[i] = 0;
                } else {
                    pickups[i] -= pickCnt;
                    break;
                }
            }
            answer += (pos+1)*2;
        }
        
        return answer;
    }
}