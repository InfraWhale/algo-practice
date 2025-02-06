// 내 풀이(1문제 런타임에러)

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
        zoneQty = new int[land_depth * land_width + 4];
        boolean[] zoneCheck = new boolean[land_depth * land_width + 4];
        
        int maxOil = 0;
        zoneNumber = 1;
        for(int j = 0; j < land_depth; j++) {
            Arrays.fill(visited[j], 0);
        }
        
        
        for(int i = 0; i < land_width; i++) {
            //System.out.println(i + "번째 줄");
            Arrays.fill(zoneCheck, false);
            
            int oil = 0;
            
            for(int j = 0; j < land_depth; j++) {
                
                if(sLand[j][i] == 0 || zoneCheck[visited[j][i]]) continue; // 땅이면 패스 or 이미 채굴했으면 패스
                if(visited[j][i] == 0) { // 아직 발견하지 못한 유전이면
                    zoneQty[zoneNumber] = dfs(j, i);
                    oil += zoneQty[zoneNumber];
                    //System.out.println("case1 : " + zoneQty[zoneNumber]);
                    zoneCheck[zoneNumber] = true;
                    zoneNumber++;
                } else { // 이전에 발견한 적이 있는 유전이면
                    oil += zoneQty[visited[j][i]];
                    //System.out.println("case2 : " + zoneQty[visited[j][i]]);
                    zoneCheck[visited[j][i]] = true;
                }
            }
            maxOil = Math.max(oil, maxOil);
        }
        
        return maxOil;
    }
    
    public int dfs(int y, int x) {
        int oil = 1;
        visited[y][x] = zoneNumber;
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= land_depth || nx < 0 || nx >= land_width || visited[ny][nx] != 0 || sLand[ny][nx] == 0) continue;
            oil += dfs(ny, nx);
        }
        return oil;
    }
}