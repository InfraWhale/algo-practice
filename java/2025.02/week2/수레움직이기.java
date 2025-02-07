// 채점 결과
// 정확성: 83.7
// 합계: 83.7 / 100.0

import java.util.*;

class Solution {
    
    static int[][] visitedRed;
    static int[][] visitedBlue;
    static int redEndY, redEndX;
    static int blueEndY, blueEndX;
    static int minTurn;
    static int depth, width;
    static int [] dy = {-1, 0, 1, 0};
    static int [] dx = {0, 1, 0, -1};
    static int[][] sMaze;
    
    public int solution(int[][] maze) {
        sMaze = maze;
        int answer = 0;
        minTurn = 20;
        depth = maze.length;
        width = maze[0].length;
        
        int redStartY = -1, redStartX = -1;
        int blueStartY = -1, blueStartX = -1;
        
        visitedRed = new int[depth][width];
        visitedBlue = new int[depth][width];
        for(int i = 0; i < depth; i++) {
            Arrays.fill(visitedRed[i], 0);
            Arrays.fill(visitedBlue[i], 0);
        }
        
        for(int i = 0; i < depth; i++) {
            for(int j = 0; j < width; j++) {
                if(maze[i][j] == 1) {
                    redStartY = i;
                    redStartX = j;
                    visitedRed[i][j] = 1;
                } else if(maze[i][j] == 2) {
                    blueStartY = i;
                    blueStartX = j;
                    visitedBlue[i][j] = 1;
                } else if(maze[i][j] == 3) {
                    redEndY = i;
                    redEndX = j;
                } else if(maze[i][j] == 4) {
                    blueEndY = i;
                    blueEndX = j;
                }
            }
        }
        
        findMinTurn(redStartY, redStartX, blueStartY, blueStartX, 0);
        
        return minTurn == 20 ? 0 : minTurn;
    }
    
    public void findMinTurn(int redY, int redX, int blueY, int blueX, int turn) {
        boolean redFlag = true;
        boolean blueFlag = true;
        if(redY == redEndY && redX == redEndX) redFlag = false;
        if(blueY == blueEndY && blueX == blueEndX) blueFlag = false;
        if(!redFlag && !blueFlag) { // 기저사례
            minTurn = Math.min(minTurn, turn);
            return;
        }
        
        // 빨강이 먼저 움직이는 경우
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int nry = redY;
                int nrx = redX;
                if(redFlag) {
                    nry += dy[i];
                    nrx += dx[i];
                    if(nry < 0 || nry >= depth || nrx < 0 || nrx >= width || visitedRed[nry][nrx] == 1 || sMaze[nry][nrx] == 5 || (nry == blueY && nrx == blueX)) continue;
                }
                int nby = blueY;
                int nbx = blueX;
                if(blueFlag) {
                    nby += dy[j];
                    nbx += dx[j];
                    if(nby < 0 || nby >= depth || nbx < 0 || nbx >= width || visitedBlue[nby][nbx] == 1 || sMaze[nby][nbx] == 5 || (nby == nry && nbx == nrx)) continue;
                }
                visitedRed[nry][nrx] = 1;
                visitedBlue[nby][nbx] = 1;
                findMinTurn(nry, nrx, nby, nbx, turn + 1);
                visitedRed[nry][nrx] = 0;
                visitedBlue[nby][nbx] = 0;
            }
        }
        
        // 파랑이 먼저 움직이는 경우
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int nby = blueY;
                int nbx = blueX;
                if(blueFlag) {
                    nby += dy[i];
                    nbx += dx[i];
                    if(nby < 0 || nby >= depth || nbx < 0 || nbx >= width || visitedBlue[nby][nbx] == 1 || sMaze[nby][nbx] == 5 || (nby == redY && nbx == redX)) continue;
                }
                int nry = redY;
                int nrx = redX;
                if(redFlag) {
                    nry += dy[i];
                    nrx += dx[i];
                    if(nry < 0 || nry >= depth || nrx < 0 || nrx >= width || visitedRed[nry][nrx] == 1 || sMaze[nry][nrx] == 5 || (nry == nby && nrx == nbx)) continue;
                }
                visitedRed[nry][nrx] = 1;
                visitedBlue[nby][nbx] = 1;
                findMinTurn(nry, nrx, nby, nbx, turn + 1);
                visitedRed[nry][nrx] = 0;
                visitedBlue[nby][nbx] = 0;
            }
        }
        
        return;
    }
}