// 채점 결과
// 정확성: 54.5
// 합계: 54.5 / 100.0

import java.util.*;

class Solution {
    
    char[][] cBoard;
    
    public int solution(int m, int n, String[] board) {
        int answer = 0;
        cBoard = new char[m][n];
        
        for(int i = 0; i < board.length; i++) {
            String boardElem = board[i];
            cBoard[i] = boardElem.toCharArray();
        }
        
        while(true) {
            int loopCnt = 0;
            for(int i = 0; i < m-1; i++) {
                for(int j = 0; j < n-1; j++) {
                    if(cBoard[i][j] =='Z') continue;
                    loopCnt += checkBlock(i, j);
                }
            }
            if(loopCnt == 0) break;
            answer += loopCnt;
            
            // 블록 떨어뜨리기
            for(int j = 0; j < n; j++) {
                for(int i = m-1; i > 0; i--) {
                    if (cBoard[i][j] == 'Z') {
                        int minus = 1;
                        // 연속된 빈 공간 구하기
                        for(int k = i-1; k >= 0; k--) {
                            if(cBoard[k][j] == 'Z') minus++;
                            else break;
                        }
                        // 빈 공간 만큼 아래로 떨구기
                        for(int k = i-minus; k >= 0; k--) {
                            cBoard[k+minus][j] = cBoard[k][j];
                        }
                        // 윗부분 채우기
                        for(int k = 0; k < minus; k++) {
                            cBoard[k][j] = 'Z';
                        }
                    }
                }
            }
            // for(int i = 0; i < m; i++) {
            //     System.out.println(Arrays.toString(cBoard[i]));
            // }
            
        }
        
        return answer;
    }
    
    public int checkBlock(int y, int x) {
        if(cBoard[y][x] == 'Z') return 0;
        if(y + 1 >= cBoard.length || x + 1 >= cBoard.length) return 0;
        
        int cnt = 0;
        
        if(cBoard[y][x] == cBoard[y+1][x] && cBoard[y][x] == cBoard[y][x+1] && cBoard[y][x] == cBoard[y+1][x+1]) {
            cnt += checkBlock(y+1, x);
            cnt += checkBlock(y, x+1);
            cnt += checkBlock(y+1, x+1);
            
            cnt += deleteBlock(y, x);
            cnt += deleteBlock(y, x+1);
            cnt += deleteBlock(y+1, x);
            cnt += deleteBlock(y+1, x+1);
            
            return cnt;
        }
        return 0;
    }
    
    public int deleteBlock(int y, int x) {
        if(cBoard[y][x] != 'Z') {
            cBoard[y][x] = 'Z';
            return 1;
        }
        return 0;
    }
}