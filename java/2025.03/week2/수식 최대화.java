// 다시 볼 것!

import java.util.*;

class Solution {
    public long solution(String expression) {
        long answer = 0;
        
        StringBuilder sb = new StringBuilder();
        List<Long> numList = new ArrayList<>();
        List<Character> exList = new ArrayList<>();
        
        for(int i = 0; i < expression.length(); i++) {
            char nowChar = expression.charAt(i);
            if(nowChar == '+' || nowChar == '-' || nowChar == '*') {
                exList.add(nowChar);
                numList.add(Long.parseLong(sb.toString()));
                sb.setLength(0);
            } else {
                sb.append(nowChar);
            }
        }
        numList.add(Long.parseLong(sb.toString()));
        
        char[][] priorities = {
            {'+', '-', '*'}, {'+', '*', '-'},
            {'-', '+', '*'}, {'-', '*', '+'},
            {'*', '+', '-'}, {'*', '-', '+'},
        };
        
        for(char[] priority : priorities) {
            answer = Math.max(answer, calculate(numList, exList, priority));
        }
        
        return answer;
    }
    
    private long calculate(List<Long> numList, List<Character> exList, char[] priority) {
        List<Long> tempNums = new ArrayList<>(numList);
        List<Character> tempExs = new ArrayList<>(exList);
        
        for(char op : priority) {
            for (int i = 0; i < tempExs.size(); ) {
                if(tempExs.get(i) == op) {
                    long result = operate(tempNums.get(i), tempNums.get(i+1), op);
                    
                    tempNums.set(i, result);
                    tempNums.remove(i + 1);
                    tempExs.remove(i);
                } else {
                    i++;
                }
            }
        }
        return Math.abs(tempNums.get(0));
    }
    
    private long operate(long a, long b, char op) {
        switch(op) {
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
        }
        return 0;
    }
}