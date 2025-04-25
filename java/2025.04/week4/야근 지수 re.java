// 리팩토링 버전

import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        
        // ✅ 전체 작업량 합
        long total = 0;
        for (int work : works) {
            total += work;
        }

        // ✅ n이 전체 작업량 이상이면 야근 지수는 무조건 0
        if (n >= total) return 0;

        Arrays.sort(works);
        int end = works.length - 1;
        int start = end;

        while (n > 0) {
            start--;

            if (start == -1) {
                int count = end + 1;
                n = reduceWorks(works, 0, end, n, count);
                break;
            } else if (works[start] != works[end]) {
                int count = end - start;
                int diff = works[end] - works[start];

                if (diff * count <= n) {
                    for (int i = end; i > start; i--) {
                        works[i] -= diff;
                    }
                    n -= diff * count;
                } else {
                    n = reduceWorks(works, start + 1, end, n, count);
                    break;
                }
            }
        }

        for (int work : works) {
            answer += (long) work * work;
        }

        return answer;
    }

    // ✅ 특정 구간의 work 값을 분배 방식으로 감소시키는 메서드
    private int reduceWorks(int[] works, int from, int to, int n, int count) {
        int divide = n / count;
        int remain = n % count;

        for (int i = to; i > to - remain; i--) {
            works[i] -= (divide + 1);
        }
        for (int i = to - remain; i >= from; i--) {
            works[i] -= divide;
        }

        return 0; // 남은 n은 다 썼으므로 0
    }
}