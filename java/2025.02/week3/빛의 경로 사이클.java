import java.util.*;

class Solution {
    static int row, column;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    
    public int[] solution(String[] grid) {
        int[] answer;
        List<Integer> answerList = new ArrayList<>();
        
        row = grid.length;
        column = grid[0].length();
        
        int[][] gridVector = new int[row][column]; // 비트마스킹 이용
        String [][] zone = new String [row][column];
        
        for(int i = 0; i < row; i++) {
            String temp = grid[i];
            for(int j = 0; j < column; j++) {
                zone[i][j] = temp.substring(j, j+1);
            }
        }
        
        int zeroCount = 0;
        
        for(int i = 0; i <= 3; i++) {
            for(int j = 0; j < row; j++) {
                Arrays.fill(gridVector[j], 0);
            }
            if((zeroCount & i) != 0) continue;
            gridVector[0][0] += (1 << i);
            int nextVector = i;
            int nextY = getNextY(nextVector, 0);
            int nextX = getNextX(nextVector, 0);
            int zoneCount = 1;
            int distCount = 1;
            
            while(true) {
                if(gridVector[nextY][nextX] == 0) zoneCount++;
                nextVector = getNextVector(zone[nextY][nextX], nextVector);
                if((gridVector[nextY][nextX] & (1 << nextVector)) != 0) break;
                
                gridVector[nextY][nextX] += (1 << nextVector);
                nextY = getNextY(nextVector, nextY);
                nextX = getNextX(nextVector, nextX);
                distCount++;
            }
            if (zoneCount == row*column) {
                answerList.add(distCount);
                zeroCount += gridVector[0][0];
            }
        }
        answer = answerList.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
    
    public static int getNextY(int vector, int y) {
        y += dy[vector];
        if (y>= row) y = 0;
        else if (y < 0) y = row-1;
        return y;
    }
    
    public static int getNextX(int vector, int x) {
        x += dx[vector];
        if (x>= column) x = 0;
        else if (x < 0) x = column-1;
        return x;
    }
    
    public static int getNextVector(String zoneStr, int vector) {
        if(zoneStr.equals("L")) vector--;
        else if(zoneStr.equals("R")) vector++;
        if(vector > 3) vector = 0;
        else if(vector < 0) vector = 3;
        return vector;
    }
}