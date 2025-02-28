import java.util.*;

class Solution {
    
    char[][] cStorage;
    boolean[][] visited, accessable;
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, 1, 0, -1};
    int yLen, xLen;
    
    public int solution(String[] storage, String[] requests) {
        yLen = storage.length;
        xLen = storage[0].length();
        
        int answer = yLen * xLen;
        
        cStorage = new char[yLen][xLen];
        visited = new boolean[yLen][xLen];
        accessable = new boolean[yLen][xLen];
        
        for(int i = 0; i < yLen; i++) {
            String temp = storage[i];
            for(int j = 0; j < xLen; j++) {
                cStorage[i][j] = temp.charAt(j);
            }
        }
        
        Arrays.fill(accessable[0], true);
        Arrays.fill(accessable[yLen-1], true);
        for(int i = 0; i < yLen; i++) {
            accessable[i][0] = true;
            accessable[i][xLen-1] = true;
        }
        
        Queue<int[]> que = new LinkedList<>();
        
        for(String request : requests) {
            boolean isCrane = request.length() == 2 ? true : false;
            char cReq = request.charAt(0);
            
            for(int i = 0; i < yLen; i++) {
                for(int j = 0; j < xLen; j++) {
                    if(visited[i][j]) continue;
                    if(cReq == cStorage[i][j]) {
                        if(accessable[i][j]) {
                            visited[i][j] = true;
                            answer--;
                            que.offer(new int[]{i, j});
                        } else if(isCrane) {
                            visited[i][j] = true;
                            answer--;
                        }
                    }
                }
            }
            
            while(que.size() != 0) {
                int[] temp = que.poll();
                accessable[temp[0]][temp[1]] = true;
                makeAccess(temp[0], temp[1]);
            }
        }
        

        return answer;
    }
    
    public void makeAccess(int y, int x) {
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= yLen || nx < 0 || nx >= xLen) continue;
            if(accessable[ny][nx]) continue;
            accessable[ny][nx] = true;
            if(visited[ny][nx]) makeAccess(ny, nx);
        }
        
        return;
    }
}