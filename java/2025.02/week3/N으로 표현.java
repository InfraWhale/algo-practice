// 채점 결과
// 정확성: 77.8
// 합계: 77.8 / 100.0

import java.util.*;

class Solution {
    public int solution(int N, int number) {
        Map<Integer, Integer> countMap = new HashMap<>();
        Map<Integer, List<Integer>> creatingMap = new HashMap<>();
        int initialNum = 0;
        
        for(int i = 1; i <= 8; i++) {
            creatingMap.put(i, new ArrayList<>());
            
            initialNum = initialNum * 10 + N;
            creatingMap.get(i).add(initialNum);
            countMap.put(initialNum, i);
        }
        
        for(int size = 2; size <= 8; size++) {
            for(int first = 1; first <= size-1; first++) {
                int second = size - first;
                for(int firstNum : creatingMap.get(first)) {
                    for(int secondNum : creatingMap.get(second)) {
                        int temp = firstNum + secondNum;
                        if(temp == number) return size;
                        if(!countMap.containsKey(temp)) {
                            countMap.put(temp, size);
                            creatingMap.get(size).add(temp);
                        }
                        temp = firstNum - secondNum;
                        if(temp == number) return size;
                        if(!countMap.containsKey(temp)) {
                            countMap.put(temp, size);
                            creatingMap.get(size).add(temp);
                        }
                        temp = firstNum * secondNum;
                        if(temp == number) return size;
                        if(!countMap.containsKey(temp)) {
                            countMap.put(temp, size);
                            creatingMap.get(size).add(temp);
                        }
                        if(secondNum != 0) {
                            temp = firstNum / secondNum;
                            if(temp == number) return size;
                            if(!countMap.containsKey(temp)) {
                                countMap.put(temp, size);
                                creatingMap.get(size).add(temp);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
}