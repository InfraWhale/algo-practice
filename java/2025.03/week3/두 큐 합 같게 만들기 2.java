// gpt 풀이

import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int n = queue1.length; // 각 큐의 길이
        long sum1 = 0, sum2 = 0, totalSum = 0; 
        int maxOperations = n * 4; // 최대 이동 횟수
        
        // 두 큐를 Deque로 변환
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();
        
        for (int i = 0; i < n; i++) {
            sum1 += queue1[i];
            sum2 += queue2[i];
            q1.offer(queue1[i]);
            q2.offer(queue2[i]);
        }
        
        totalSum = sum1 + sum2;
        
        // 총합이 홀수면 두 큐를 같게 만들 수 없음
        if (totalSum % 2 == 1) return -1;
        
        long target = totalSum / 2;
        int operations = 0;
        
        while (sum1 != target && operations < maxOperations) {
            if (sum1 > target) { // queue1이 크면 queue1에서 queue2로 이동
                int value = q1.poll();
                sum1 -= value;
                sum2 += value;
                q2.offer(value);
            } else { // queue2가 크면 queue2에서 queue1로 이동
                int value = q2.poll();
                sum2 -= value;
                sum1 += value;
                q1.offer(value);
            }
            operations++;
        }
        
        return (sum1 == target) ? operations : -1;
    }
}
