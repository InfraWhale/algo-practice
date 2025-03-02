//gpt 풀이

class Solution {
    public int[] solution(int[] sequence, int k) {
        int left = 0, right = 0;
        int sum = sequence[0];
        int n = sequence.length;

        int minLength = Integer.MAX_VALUE;
        int[] answer = new int[2];

        while (right < n) {
            if (sum == k) {
                // 더 짧은 구간을 찾기 위해 갱신
                if (right - left < minLength) {
                    minLength = right - left;
                    answer[0] = left;
                    answer[1] = right;
                }
                sum -= sequence[left++];
            } else if (sum < k) {
                if (++right < n) sum += sequence[right];
            } else {
                sum -= sequence[left++];
            }
        }

        return minLength == Integer.MAX_VALUE ? new int[] {} : answer;
    }
}
