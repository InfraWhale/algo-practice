import java.util.*;

class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int[][] matrix = new int[rows+1][columns+1];
        
        int num = 1;
        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= columns; j++) {
                matrix[i][j] = num++;
            }
        }
        
        int[] answer = new int[queries.length];
        int idx = 0;
        for(int[] query : queries) {
            int minVal = num;
            
            int upLeft = matrix[query[0]][query[1]];
            minVal = Math.min(minVal, upLeft);
            int upRight = matrix[query[0]][query[3]];
            minVal = Math.min(minVal, upRight);
            int downLeft = matrix[query[2]][query[1]];
            minVal = Math.min(minVal, downLeft);
            int downRight = matrix[query[2]][query[3]];
            minVal = Math.min(minVal, downRight);
            
            for(int i = query[3] - 1; i > query[1]; i--) {
                matrix[query[0]][i + 1] = matrix[query[0]][i];
                minVal = Math.min(minVal, matrix[query[0]][i]);
            }
            matrix[query[0]][query[1] + 1] = upLeft;
            
            for(int i = query[2] - 1; i > query[0]; i--) {
                matrix[i + 1][query[3]] = matrix[i][query[3]];
                minVal = Math.min(minVal, matrix[i][query[3]]);
            }
            matrix[query[0] + 1][query[3]] = upRight;
            
            for(int i = query[1] + 1; i < query[3]; i++) {
                matrix[query[2]][i - 1] = matrix[query[2]][i];
                minVal = Math.min(minVal, matrix[query[2]][i]);
            }
            matrix[query[2]][query[3] - 1] = downRight;
            
            for(int i = query[0] + 1; i < query[2]; i++) {
                matrix[i - 1][query[1]] = matrix[i][query[1]];
                minVal = Math.min(minVal, matrix[i][query[1]]);
            }
            matrix[query[2] - 1][query[1]] = downLeft;
            answer[idx++] = minVal;
        }
        
        return answer;
    }
}