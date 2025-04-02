// gpt 이용 리팩토링

import java.util.*;

class Solution {
    public int[] solution(String msg) {
        Map<String, Integer> dictionary = new HashMap<>();
        for (int i = 0; i < 26; i++) {
            dictionary.put(String.valueOf((char) ('A' + i)), i + 1);
        }

        List<Integer> output = new ArrayList<>();
        int nextIndex = 27;

        for (int i = 0; i < msg.length(); ) {
            StringBuilder w = new StringBuilder();
            w.append(msg.charAt(i));
            int j = i + 1;

            while (j <= msg.length() && dictionary.containsKey(w.toString())) {
                if (j == msg.length()) break;
                w.append(msg.charAt(j));
                j++;
            }

            if (!dictionary.containsKey(w.toString())) {
                w.deleteCharAt(w.length() - 1); // 마지막 글자 제거하여 기존 사전 키로 되돌림
            }

            output.add(dictionary.get(w.toString()));

            // 다음 단어 등록 (w+c가 사전에 없었다면)
            if (i + w.length() < msg.length()) {
                String wc = msg.substring(i, i + w.length() + 1);
                dictionary.put(wc, nextIndex++);
            }

            i += w.length(); // 다음 탐색 위치 이동
        }

        return output.stream().mapToInt(i -> i).toArray();
    }
}
