import java.util.*;

class Solution {
    
    char[][] standby = new char[5][5];
    boolean flag;
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, 1, 0, -1};
    
    public int[] solution(String[][] places) {
        int[] answer = new int [places.length];
        
        int idx = 0;
        for(String[] place : places) {
            
            for(int i=0; i<5; i++) {
                String row = place[i];
                for(int j=0; j<5; j++) {
                    standby[i][j] = row.charAt(j);
                }
            }
            
            flag = false;
            for(int i=0; i<5; i++) {
                for(int j=0; j<5; j++) {
                    if(standby[i][j] == 'P') {
                        flag = bfs(i, j);
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
            answer[idx] = flag ? 0 : 1;
            idx++;
        }
        
        return answer;
    }
    
    public boolean bfs(int y, int x) {
        Queue<int[]> que = new LinkedList<>();
        
        que.offer(new int[] {y, x});
        int[][] visited = new int[5][5];
        visited[y][x] = 1;
        while(!que.isEmpty()) {
            int[] now = que.poll();
            
            for(int i = 0; i < 4; i++) {
                int ny = now[0] + dy[i];
                int nx = now[1] + dx[i];
                
                if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || standby[ny][nx] == 'X' || visited[ny][nx] != 0) continue;
                if(standby[ny][nx] == 'P') return true;
                
                visited[ny][nx] = visited[now[0]][now[1]] +1;
                if(visited[ny][nx] == 2) que.offer(new int[] {ny, nx});
            }
        }
        
        return false;
    }
}