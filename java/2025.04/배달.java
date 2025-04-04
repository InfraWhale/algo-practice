import java.util.*;

class Solution {
    
    int[] visited;
    List<Integer>[] adjList;
    int[][] matrix;
    
    public int solution(int N, int[][] road, int K) {
        
        adjList = new List[N+1];
        for(int i = 1; i <= N; i++) {
            adjList[i] = new ArrayList<>();
        }
        matrix = new int[N+1][N+1];
        
        for(int i = 0; i < road.length; i++) {
            int first = road[i][0];
            int second = road[i][1];
            int time = road[i][2];
            if(matrix[first][second] == 0) {
                adjList[first].add(second);
                adjList[second].add(first);
                matrix[first][second] = time;
                matrix[second][first] = time;
            }
            else if(matrix[first][second] > time) {
                matrix[first][second] = time;
                matrix[second][first] = time;
            }
        }
        
        visited = new int[N+1];
        visited[1] = -1;
        dfs(1, 0);
        
        int answer = 1;
        for(int i = 2; i <= N; i++) {
            if(visited[i] <= K) answer++;
        }
        return answer;
    }
    
    public void dfs (int now, int totalTime) {
        for(int next : adjList[now]) {
            int nextTotalTime = totalTime + matrix[now][next];
            if(visited[next] == 0 || visited[next] > nextTotalTime) {
                visited[next] = nextTotalTime;
                dfs(next, nextTotalTime);
            }
        }
        return;
    }
}