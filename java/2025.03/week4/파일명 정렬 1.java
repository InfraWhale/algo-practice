// 정규식 사용

import java.util.*;
import java.util.regex.*;

class Solution {
    public String[] solution(String[] files) {
        // 파일 정보를 [HEAD, NUMBER, 원본 파일명] 형태로 저장
        String[][] parsed = new String[files.length][3];
        Pattern pattern = Pattern.compile("([a-zA-Z\\-\\.\\s]+)(\\d{1,5})");

        for (int i = 0; i < files.length; i++) {
            Matcher matcher = pattern.matcher(files[i]);
            if (matcher.find()) {
                parsed[i][0] = matcher.group(1);         // HEAD
                parsed[i][1] = matcher.group(2);         // NUMBER
                parsed[i][2] = files[i];                 // 원본 전체
            }
        }

        // 정렬
        Arrays.sort(parsed, Comparator
                .comparing((String[] f) -> f[0].toLowerCase())
                .thenComparingInt(f -> Integer.parseInt(f[1]))
        );

        // 정렬 결과에서 원본 파일명만 추출
        String[] answer = new String[files.length];
        for (int i = 0; i < files.length; i++) {
            answer[i] = parsed[i][2];
        }

        return answer;
    }
}