// 정답

import java.util.*;

class Solution {
    private List<List<Integer>> possibleDistributions = new ArrayList<>(); // 가능한 상담원 배치 경우의 수
    
    public int solution(int k, int n, int[][] reqs) {
        int minTotalWaitTime = Integer.MAX_VALUE;
        Integer[] initialDistribution = new Integer[k + 1];
        Arrays.fill(initialDistribution, 1);

        // 상담원 배치를 모든 경우의 수로 생성
        generateDistributions(n - k, 1, new ArrayList<>(Arrays.asList(initialDistribution)));
        System.out.println(possibleDistributions);

        // 모든 경우의 수에 대해 시뮬레이션 실행하여 최소 대기 시간 계산
        for (List<Integer> distribution : possibleDistributions) {
            minTotalWaitTime = Math.min(minTotalWaitTime, runSimulation(k, distribution, reqs));
        }

        return minTotalWaitTime;
    }

    // 🔹 상담원 배치를 재귀적으로 생성하는 함수
    private void generateDistributions(int remainingMentors, int type, List<Integer> distribution) {
        if (remainingMentors == 0) {
            possibleDistributions.add(new ArrayList<>(distribution)); // 완성된 배치를 저장
            return;
        }

        for (int i = type; i < distribution.size(); i++) {
            distribution.set(i, distribution.get(i) + 1);
            generateDistributions(remainingMentors - 1, i, new ArrayList<>(distribution));
            distribution.set(i, distribution.get(i) - 1); // 원래 값 복구
        }
    }

    // 🔹 특정 상담원 배치에서 총 대기 시간을 계산하는 시뮬레이션 함수
    private int runSimulation(int k, List<Integer> distribution, int[][] reqs) {
        PriorityQueue<Integer>[] mentorQueues = new PriorityQueue[k + 1];
        int totalWaitTime = 0;

        // 상담 유형별 상담원 큐 초기화
        for (int i = 1; i <= k; i++) {
            mentorQueues[i] = new PriorityQueue<>();
            for (int j = 0; j < distribution.get(i); j++) {
                mentorQueues[i].add(0); // 초기 상담원 가용 시간을 0으로 설정
            }
        }

        // 각 요청에 대해 처리
        for (int[] req : reqs) {
            int requestTime = req[0]; // 요청 시간
            int duration = req[1]; // 상담 소요 시간
            int type = req[2]; // 상담 유형

            int earliestAvailableTime = mentorQueues[type].poll(); // 해당 유형에서 가장 빨리 가능한 상담원 선택

            if (earliestAvailableTime > requestTime) { // 상담원이 바쁠 경우 대기 시간 발생
                totalWaitTime += (earliestAvailableTime - requestTime);
                mentorQueues[type].add(earliestAvailableTime + duration);
            } else { // 상담원이 대기 중이라 바로 상담 가능
                mentorQueues[type].add(requestTime + duration);
            }
        }

        return totalWaitTime;
    }
}