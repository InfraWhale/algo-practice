// 만들다 만 코드

import java.util.*;

public class Applicant {
    String language;
    String type;
    String rank;
    String food;
    int score;
    
    public Applicant(String language, String type, String rank, String food, int score) {
        this.language = language;
        this.type = type;
        this.rank = rank;
        this.food = food;
        this.score = score;
    }
}

class Solution {
    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];
        Arrays.fill(answer, 0);
        
        List<Applicant> table = new ArrayList<>();
        
        for (String s : info) {
            String[] nowInfo = s.split(" ");
            table.add(new Applicant(nowInfo[0], nowInfo[1], nowInfo[2], nowInfo[3], Integer.parseInt(nowInfo[4])));
        }
        
        for (int i = 0; i < query.length; i++) {
            String[] nowQuery = query[i].split(" ");
            List<Applicant> nowTable = new ArrayList<>(table);
            
            int start, end;
            
            // 언어 체크
            if (!nowQuery[0].equals("-")) {
                nowTable.sort(Comparator.comparing(applicant -> applicant.language));
                start = lowerBound(nowTable, nowQuery[0], Comparator.comparing(applicant -> applicant.language));
                end = upperBound(nowTable, nowQuery[0], Comparator.comparing(applicant -> applicant.language));
                if (start == end) continue;
                nowTable = nowTable.subList(start, end);
            }
            
            // 직군 체크
            if (!nowQuery[2].equals("-")) {
                nowTable.sort(Comparator.comparing(applicant -> applicant.type));
                start = lowerBound(nowTable, nowQuery[2], Comparator.comparing(applicant -> applicant.type));
                end = upperBound(nowTable, nowQuery[2], Comparator.comparing(applicant -> applicant.type));
                if (start == end) continue;
                nowTable = nowTable.subList(start, end);
            }
            
            // 경력 체크
            if (!nowQuery[4].equals("-")) {
                nowTable.sort(Comparator.comparing(applicant -> applicant.rank));
                start = lowerBound(nowTable, nowQuery[4], Comparator.comparing(applicant -> applicant.rank));
                end = upperBound(nowTable, nowQuery[4], Comparator.comparing(applicant -> applicant.rank));
                if (start == end) continue;
                nowTable = nowTable.subList(start, end);
            }
            
            // 음식 체크
            if (!nowQuery[6].equals("-")) {
                nowTable.sort(Comparator.comparing(applicant -> applicant.food));
                start = lowerBound(nowTable, nowQuery[6], Comparator.comparing(applicant -> applicant.food));
                end = upperBound(nowTable, nowQuery[6], Comparator.comparing(applicant -> applicant.food));
                if (start == end) continue;
                nowTable = nowTable.subList(start, end);
            }
            
            // 점수 체크
            int score = Integer.parseInt(nowQuery[7]);
            nowTable.sort(Comparator.comparingInt(applicant -> applicant.score));
            start = lowerBoundScore(nowTable, score);
            if (start == nowTable.size()) continue;
            nowTable = nowTable.subList(start, nowTable.size());
            
            answer[i] = nowTable.size();
        }
        
        return answer;
    }
    
    public static int lowerBound(List<Applicant> list, String target, Comparator<Applicant> comparator) {
        int left = 0, right = list.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (comparator.compare(list.get(mid), new Applicant(target, "", "", "", 0)) < 0) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    public static int upperBound(List<Applicant> list, String target, Comparator<Applicant> comparator) {
        int left = 0, right = list.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (comparator.compare(list.get(mid), new Applicant(target, "", "", "", 0)) <= 0) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    
    public static int lowerBoundScore(List<Applicant> list, int score) {
        int left = 0, right = list.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (list.get(mid).score < score) left = mid + 1;
            else right = mid;
        }
        return left;
    }
}
