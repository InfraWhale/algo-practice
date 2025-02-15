class Solution {
    public int[] solution(int m, int n, int startX, int startY, int[][] balls) {
        //int[] answer = {};
        
        int ballsLength = balls.length;
        int[] answer = new int[ballsLength];
        
        for(int i = 0; i < ballsLength; i++) {
            int minVal = 987654321;
            int ballX = balls[i][0];
            int ballY = balls[i][1];
            
            // case1
            if(!((startX == ballX) && (startY < ballY))) {
                minVal= Math.min(minVal, (int) (Math.pow(2*n-ballY-startY,2) + Math.pow(ballX-startX,2)));
            }
            
            // case2
            if(!((startY == ballY) && (startX < ballX))) {
                minVal= Math.min(minVal, (int) (Math.pow(2*m-ballX-startX,2) + Math.pow(ballY-startY,2)));
            }
            
            // case3
            if(!((startX == ballX) && (startY > ballY))) {
                minVal= Math.min(minVal, (int) (Math.pow(ballY+startY,2) + Math.pow(ballX-startX,2)));
            }
            
            // case4
            if(!((startY == ballY) && (startX > ballX))) {
                minVal= Math.min(minVal, (int) (Math.pow(ballX+startX,2) + Math.pow(ballY-startY,2)));
            }
            
            answer[i] = minVal;
        }
        
        return answer;
    }
}