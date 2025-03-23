// 시행착오 많이 거침

import java.util.*;

class Solution {
    
    List<Integer> combiList = new ArrayList<>();
    List<String> keyList = new ArrayList<>();
    int rowLen, columnLen;
    String[][] sRelation;
    
    public int solution(String[][] relation) {
        rowLen = relation.length;
        columnLen = relation[0].length;
        sRelation = relation;
        
        for(int targetSize = 1; targetSize <= columnLen; targetSize++) {
            makeCombi(0, targetSize);
        }
        
        return keyList.size();
    }
    
    void makeCombi(int startColumn, int targetSize) {
        if(combiList.size() == targetSize) {
            check();
            return;
        }
        
        for(int i = startColumn; i < columnLen; i++) {
            combiList.add(i);
            makeCombi(i+1, targetSize);
            combiList.remove(combiList.size() - 1);
        }
        return;
    }
    
    boolean check() {
        Set<String> candidateSet = new HashSet<>();
        
        // 유일성 검사
        for(int i = 0; i < rowLen; i++) {
            String key = "";
            for(int j : combiList) {
                key += sRelation[i][j];
            }
            if(candidateSet.contains(key)) return false;
            candidateSet.add(key);
        }
        
        String nowKey = "";
        for(int i : combiList) {
            nowKey += String.valueOf(i);
        }
        
        // 최소성 검사
        for(String prevKey : keyList) {
            int count = 0;
            for(String elem : prevKey.split("")) {
                if(nowKey.contains(elem)) count++;
            }
            if(count == prevKey.length()) return false;
        }
        
        keyList.add(nowKey);
        return true;
    }
}