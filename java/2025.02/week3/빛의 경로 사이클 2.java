// gpt 풀이

import java.util.*;

class Solution {
    static int row, column;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public int[] solution(String[] grid) {
        List<Integer> answerList = new ArrayList<>();
        
        row = grid.length;
        column = grid[0].length();
        
        char[][] zone = new char[row][column];
        boolean[][][] visited = new boolean[row][column][4]; // [y][x][방향]
        
        for (int i = 0; i < row; i++) {
            zone[i] = grid[i].toCharArray();
        }
        
        for (int y = 0; y < row; y++) {
            for (int x = 0; x < column; x++) {
                for (int dir = 0; dir < 4; dir++) {
                    if (!visited[y][x][dir]) {  // 방문하지 않은 경로 탐색 시작
                        answerList.add(getCycleLength(y, x, dir, zone, visited));
                    }
                }
            }
        }
        
        return answerList.stream().mapToInt(Integer::intValue).sorted().toArray();
    }

    public static int getCycleLength(int startY, int startX, int startDir, char[][] zone, boolean[][][] visited) {
        int y = startY, x = startX, dir = startDir;
        int length = 0;

        while (!visited[y][x][dir]) {
            visited[y][x][dir] = true;  // 방문 표시
            length++;
            
            // 다음 방향 계산
            dir = getNextVector(zone[y][x], dir);
            y = getNextY(dir, y);
            x = getNextX(dir, x);
        }

        return length;
    }

    public static int getNextY(int vector, int y) {
        return (y + dy[vector] + row) % row;  // 위 아래 경계 처리
    }

    public static int getNextX(int vector, int x) {
        return (x + dx[vector] + column) % column;  // 좌우 경계 처리
    }

    public static int getNextVector(char zoneStr, int vector) {
        if (zoneStr == 'L') return (vector + 3) % 4;  // 반시계 회전
        if (zoneStr == 'R') return (vector + 1) % 4;  // 시계 회전
        return vector;  // S일 경우 그대로 유지
    }
}
