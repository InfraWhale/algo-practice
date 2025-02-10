// 2024 카카오 인턴 2번

import java.util.*;

class Solution {
    Map<Integer, List<Integer>> fromToMap;
    int[][] inAndOut;
    
    public int[] solution(int[][] edges) {
        int[] answer = {-1, 0, 0, 0};
        
        fromToMap = new HashMap<>();
        inAndOut = new int[1000000+1][2];
        
        int maxInt = -1; 
        for(int i = 0; i < edges.length; i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            if(!fromToMap.containsKey(from)) {
                fromToMap.put(from, new ArrayList<>());
            }
            List tempList = fromToMap.get(from);
            tempList.add(to);
            
            int bigger = Math.max(from, to);
            maxInt = Math.max(maxInt, bigger);
            
            inAndOut[from][0]++; // from에서 나가는 수
            inAndOut[to][1]++; // to로 들어오는 수
        }
        
        int primeNode = -1;
        for(int i = 1; i <= maxInt; i++) {
            if(inAndOut[i][0] >= 2 && inAndOut[i][1] == 0) {
                primeNode = i;
                break;
            }
        }
        answer[0] = primeNode;
        
        for(int startNode : fromToMap.get(primeNode)) {
            int graphCase = dfs(startNode, startNode, 0);
            answer[graphCase]++;
        }
        
        return answer;
    }
    
    public int dfs(int start, int now, int depth) {
        if(start == now && depth != 0) return 1; // 탐색을 시켜봤는데 자기 자신으로 돌아오면 도넛
        if(inAndOut[now][0] == 0) return 2; // 나가는게 없으면 or 탐색을 시켜보다가 나가는게 없는게 나오면 직선
        if(inAndOut[now][0] >= 2) return 3; // 탐색을 시켜봤는데 나가는게 2개인 노드를 만나면 8자
        
        for(int next : fromToMap.get(now)) {
            return dfs(start, next, depth+1);
        }
        return 0;
    }
}