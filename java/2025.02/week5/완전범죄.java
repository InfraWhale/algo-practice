// 채점 결과
// 정확성: 40.0
// 합계: 40.0 / 100.0

class Solution {
    
    int[][] sInfo;
    int aLimit, bLimit, infoLength, aMin;
    
    public int solution(int[][] info, int n, int m) {
        int answer = 0;
        
        sInfo = info;
        infoLength = info.length;
        aLimit = n;
        bLimit = m;
        aMin = 987654321;
        
        dfs(0, 0, 0);
        answer = (aMin == 987654321) ? -1 : aMin;
        
        return answer;
    }
    
    public void dfs (int item, int aCount, int bCount) {
        if(item == infoLength) {
            aMin = Math.min(aMin, aCount);
            return;
        }
        
        if(aCount+sInfo[item][0] < aLimit) {
            dfs(item+1, aCount+sInfo[item][0], bCount);
        }
        if(bCount+sInfo[item][1] < bLimit) {
            dfs(item+1, aCount, bCount+sInfo[item][1]);
        }
        return;
    }
    
}