// 풀다가 해결 못함
// 가능한 모든 조합을 찾고, 해당 조합이 q와 적합한지 확인하는 방향으로 풀어야 함

import java.util.*;

class Solution {
    int answer;
    int[][] sQ;
    int[] sAns;
    int[] state;

    public int solution(int n, int[][] q, int[] ans) {
        answer = 0;
        sQ = q;
        sAns = ans;
        state = new int[n + 1]; // 0: 미선택, 1: 비밀코드, 2: 비밀코드 아님

        dfs(0);

        return answer;
    }

    public void dfs(int depth) {
        if (depth == 5) {
            answer++;
            return;
        }

        boolean[] tempC = new boolean[5];
        makeC(depth, sAns[depth], 0, tempC, state.clone());
    }

    public void makeC(int depth, int goal, int now, boolean[] tempC, int[] prevState) {
        if (now == goal) {
            // 현재 조합이 완성되었을 때, 상태 업데이트
            int[] backupState = state.clone();

            for (int i = 0; i < 5; i++) {
                int num = sQ[depth][i];
                if (tempC[i]) {
                    state[num] = 1; // 비밀코드로 설정
                } else {
                    state[num] = 2; // 비밀코드가 아님으로 설정
                }
            }

            dfs(depth + 1);

            // 상태 복원
            state = backupState;
            return;
        }

        for (int i = 0; i < 5; i++) {
            int num = sQ[depth][i];

            // 이미 비밀코드 아님으로 확정된 숫자는 제외
            if (state[num] == 2 || tempC[i]) continue;

            // 새로운 배열로 tempC를 복사하여 각 분기마다 독립적인 선택을 유지
            boolean[] nextTempC = tempC.clone();
            nextTempC[i] = true;

            makeC(depth, goal, now + 1, nextTempC, prevState);
        }
    }
}
