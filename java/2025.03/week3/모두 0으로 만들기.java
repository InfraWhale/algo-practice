// 채점 결과
// 정확성: 72.2
// 합계: 72.2 / 100.0

import java.util.*;

class Solution {
    
    Map<Integer, List<Integer>> edgeMap;
    int[] sA;
    long cnt;
    
    public long solution(int[] a, int[][] edges) {       
        edgeMap = new HashMap<>();
        sA = a;
        
        for(int i = 0; i < a.length; i++) {
            edgeMap.put(i, new ArrayList<>());
        }
        for(int i = 0; i < edges.length; i++) {
            edgeMap.get(edges[i][0]).add(edges[i][1]);
            edgeMap.get(edges[i][1]).add(edges[i][0]);
        }
        
        int answer = dfs(0, -1);
        
        return answer == 0 ? cnt : -1;
    }
    
    int dfs(int now, int prev) {
        for(int next : edgeMap.get(now)) {
            if(next == prev) continue;
            int prevVal = dfs(next, now);
            sA[now] += prevVal;
            cnt += (long)Math.abs(prevVal);
        }
        return sA[now];
    }
}