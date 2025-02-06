// GPT 풀이

import java.util.*;

class Solution {
    static int[][] sLand;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int[][] visited;
    static int land_depth;
    static int land_width;
    static int zoneNumber;
    static int[] zoneQty;

    public int solution(int[][] land) {
        sLand = land;
        land_depth = land.length;
        land_width = land[0].length;

        visited = new int[land_depth][land_width];
        zoneQty = new int[land_depth * land_width + 10];  // 충분한 크기로 설정

        int maxOil = 0;
        zoneNumber = 1;

        // 1. 먼저 모든 유전 구역을 탐색하여 저장
        for (int j = 0; j < land_depth; j++) {
            for (int i = 0; i < land_width; i++) {
                if (sLand[j][i] == 1 && visited[j][i] == 0) { // 새로운 유전 발견 시
                    zoneQty[zoneNumber] = dfs(j, i);  // 해당 유전 크기 저장
                    zoneNumber++;
                }
            }
        }

        // 2. 각 열을 기준으로 최대 석유 채굴량 계산
        for (int i = 0; i < land_width; i++) {
            boolean[] zoneCheck = new boolean[zoneNumber + 1]; // 탐색마다 새롭게 초기화
            int oil = 0;

            for (int j = 0; j < land_depth; j++) {
                if (sLand[j][i] == 1) {
                    int zoneIdx = visited[j][i];
                    if (!zoneCheck[zoneIdx]) { // 중복된 유전이면 추가 안 함
                        oil += zoneQty[zoneIdx];
                        zoneCheck[zoneIdx] = true;
                    }
                }
            }
            maxOil = Math.max(oil, maxOil);
        }

        return maxOil;
    }

    public int dfs(int y, int x) {
        int oil = 1;
        visited[y][x] = zoneNumber;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= land_depth || nx < 0 || nx >= land_width) continue;
            if (visited[ny][nx] != 0 || sLand[ny][nx] == 0) continue;

            oil += dfs(ny, nx);
        }
        return oil;
    }
}
