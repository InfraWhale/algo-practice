import java.util.*;

class Solution {
    public int solution(int N, int number) {
        if (N == number) return 1;  // N 자체가 number라면 1 반환

        // 1~8개를 사용한 경우를 저장하는 Map
        Map<Integer, Set<Integer>> creatingMap = new HashMap<>();
        
        for (int i = 1; i <= 8; i++) {
            creatingMap.put(i, new HashSet<>());
        }
        
        // N을 1, 2, 3, ..., 8번 이어 붙인 숫자 추가
        for (int i = 1; i <= 8; i++) {
            int initialNum = Integer.parseInt(String.valueOf(N).repeat(i));
            creatingMap.get(i).add(initialNum);
        }
        
        for (int size = 2; size <= 8; size++) {
            for (int first = 1; first < size; first++) {
                int second = size - first;
                
                for (int firstNum : creatingMap.get(first)) {
                    for (int secondNum : creatingMap.get(second)) {
                        Set<Integer> tempSet = new HashSet<>();

                        tempSet.add(firstNum + secondNum);
                        tempSet.add(firstNum - secondNum);
                        tempSet.add(firstNum * secondNum);
                        if (secondNum != 0) tempSet.add(firstNum / secondNum);

                        creatingMap.get(size).addAll(tempSet);
                    }
                }
            }
            // 모든 경우를 탐색한 후 number가 존재하는지 확인
            if (creatingMap.get(size).contains(number)) return size;
        }
        
        return -1; // 8개까지 사용했는데도 number를 만들 수 없는 경우
    }
}
