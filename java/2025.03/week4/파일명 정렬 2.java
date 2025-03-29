// 정규식 X

import java.util.*;

class Solution {
    public String[] solution(String[] files) {
        String[][] parsed = new String[files.length][3]; // [HEAD, NUMBER, 원본]

        for (int i = 0; i < files.length; i++) {
            String file = files[i];
            int len = file.length();
            int idx = 0;

            // 1. HEAD
            StringBuilder head = new StringBuilder();
            while (idx < len && !Character.isDigit(file.charAt(idx))) {
                head.append(file.charAt(idx));
                idx++;
            }

            // 2. NUMBER (최대 5자리)
            StringBuilder number = new StringBuilder();
            int count = 0;
            while (idx < len && Character.isDigit(file.charAt(idx)) && count < 5) {
                number.append(file.charAt(idx));
                idx++;
                count++;
            }

            parsed[i][0] = head.toString();
            parsed[i][1] = number.toString();
            parsed[i][2] = file;
        }

        // 정렬 (TAIL 비교 없이 HEAD + NUMBER만)
        Arrays.sort(parsed, Comparator
            .comparing((String[] f) -> f[0].toLowerCase())          // HEAD
            .thenComparingInt(f -> Integer.parseInt(f[1]))          // NUMBER
        );

        // 결과 추출
        String[] answer = new String[files.length];
        for (int i = 0; i < files.length; i++) {
            answer[i] = parsed[i][2]; // 원본 파일명
        }

        return answer;
    }
}