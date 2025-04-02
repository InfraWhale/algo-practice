// 체크 & 삭제 로직 분리
// 'Z'를 '-'로 변경 (이렇게 바꿔야만 테케 하나가 맞는다?)

import java.util.*;

class Solution {
    
    char[][] cBoard;
    boolean[][] marked;
    int m, n;

    public int solution(int m, int n, String[] board) {
        int answer = 0;
        this.m = m;
        this.n = n;
        cBoard = new char[m][n];

        for(int i = 0; i < m; i++) {
            cBoard[i] = board[i].toCharArray();
        }

        while (true) {
            marked = new boolean[m][n];
            int loopCnt = 0;

            // 블록 체크
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (cBoard[i][j] != '-') {
                        checkBlock(i, j);
                    }
                }
            }

            // 표시된 블록 삭제
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (marked[i][j]) {
                        cBoard[i][j] = '-';
                        loopCnt++;
                    }
                }
            }

            if (loopCnt == 0) break;
            answer += loopCnt;

            //블록 떨어뜨리기
            for(int j = 0; j < n; j++) {
                for(int i = m-1; i > 0; i--) {
                    if (cBoard[i][j] == '-') {
                        int minus = 1;
                        // 연속된 빈 공간 구하기
                        for(int k = i-1; k >= 0; k--) {
                            if(cBoard[k][j] == '-') minus++;
                            else break;
                        }
                        // 빈 공간 만큼 아래로 떨구기
                        for(int k = i-minus; k >= 0; k--) {
                            cBoard[k+minus][j] = cBoard[k][j];
                        }
                        // 윗부분 채우기
                        for(int k = 0; k < minus; k++) {
                            cBoard[k][j] = '-';
                        }
                    }
                }
            }
            
        }

        return answer;
    }

    public void checkBlock(int y, int x) {
        if (y + 1 >= m || x + 1 >= n) return;

        char c = cBoard[y][x];
        if (c == cBoard[y+1][x] && c == cBoard[y][x+1] && c == cBoard[y+1][x+1]) {
            marked[y][x] = true;
            marked[y+1][x] = true;
            marked[y][x+1] = true;
            marked[y+1][x+1] = true;
        }
    }
}
