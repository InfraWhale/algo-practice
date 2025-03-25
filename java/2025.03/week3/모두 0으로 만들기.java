// 채점 결과
// 정확성: 88.9
// 합계: 88.9 / 100.0
// 런타임 에러 2건
 
import java.util.*;

class Solution {
    
    Map<Integer, List<Integer>> edgeMap;
    int[] sA;
    long cnt;
    
    
    public long solution(int[] a, int[][] edges) {       
        edgeMap = new HashMap<>();
        sA = a;
        
        long sum = 0;
        for (int num : a) sum += num;
        if (sum != 0) return -1;
        
        for(int i = 0; i < a.length; i++) {
            edgeMap.put(i, new ArrayList<>());
        }
        for(int i = 0; i < edges.length; i++) {
            edgeMap.get(edges[i][0]).add(edges[i][1]);
            edgeMap.get(edges[i][1]).add(edges[i][0]);
        }
        
        long answer = dfs(0, -1);
        
        return answer == 0 ? cnt : -1;
    }
    
    long dfs(int now, int prev) {
        long nowVal = (long)sA[now];
        for(int next : edgeMap.get(now)) {
            if(next == prev) continue;
            long prevVal = dfs(next, now);
            nowVal += prevVal;
            cnt += (long)Math.abs(prevVal);
        }
        return nowVal;
    }
}