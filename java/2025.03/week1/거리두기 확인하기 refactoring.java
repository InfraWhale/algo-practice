import java.util.*;

class Solution {
    
    char[][] standby;
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, 1, 0, -1};
    
    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];
        
        for(int idx = 0; idx < places.length; idx++) {
            standby = new char[5][5];
            for(int i = 0; i < 5; i++) {
                standby[i] = places[idx][i].toCharArray();
            }
            
            answer[idx] = isSafe() ? 1 : 0;
        }
        return answer;
    }
    
    private boolean isSafe() {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if (standby[i][j] == 'P' && !bfs(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private boolean bfs(int y, int x) {
        Queue<int[]> que = new LinkedList<>();
        boolean[][] visited = new boolean[5][5];
        
        que.offer(new int[]{y, x});
        visited[y][x] = true;

        while(!que.isEmpty()) {
            int[] now = que.poll();

            for(int i = 0; i < 4; i++) {
                int ny = now[0] + dy[i];
                int nx = now[1] + dx[i];
                int dist = Math.abs(ny - y) + Math.abs(nx - x);

                if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || visited[ny][nx] || standby[ny][nx] == 'X' || dist > 2) continue;
                if (standby[ny][nx] == 'P') return false;

                visited[ny][nx] = true;
                que.offer(new int[]{ny, nx});
            }
        }
        return true;
    }
}
