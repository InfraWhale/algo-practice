import java.util.*;

class Solution {
    int basicTime, basicFee, duration, durFee;  
    public int[] solution(int[] fees, String[] records) {
        
        int[] answer = {};
        basicTime = fees[0];
        basicFee = fees[1];
        duration = fees[2];
        durFee = fees[3];
        
        Map<Integer, Integer> inOutMap = new HashMap<>();
        Map<Integer, Integer> totalTimeMap = new HashMap<>();
        
        for(String record : records) {
            String[] detail = record.split(" ");
            int min = Integer.parseInt(detail[0].substring(0, 2)) * 60 + Integer.parseInt(detail[0].substring(3, 5));
            int carNum = Integer.parseInt(detail[1]);
            
            if(detail[2].equals("IN")) {
                inOutMap.put(carNum, min);
            } else {
                if(totalTimeMap.containsKey(carNum)) {
                    totalTimeMap.put(carNum, min-inOutMap.get(carNum) + totalTimeMap.get(carNum));
                } else {
                    totalTimeMap.put(carNum, min-inOutMap.get(carNum));
                }
                inOutMap.remove(carNum);
            }
        }
        
        int endTime = 23*60 + 59;
        
        for(Map.Entry<Integer, Integer> entry :inOutMap.entrySet()) {
            int carNum = entry.getKey();
            int startTime = entry.getValue();
            if(totalTimeMap.containsKey(carNum)) {
                totalTimeMap.put(carNum, endTime-startTime + totalTimeMap.get(carNum));
            } else {
                totalTimeMap.put(carNum, endTime-startTime);
            }
        }
        
        List<Integer> keySet = new ArrayList<>(totalTimeMap.keySet());
        Collections.sort(keySet);
        
        answer = new int[totalTimeMap.size()];
        int idx = 0;
        for(int carNum : keySet) {
            answer[idx] = calculateMoney(totalTimeMap.get(carNum));
            idx++;
        }
        
        return answer;
    }
    
    public int calculateMoney(int totalTime) {
        if (totalTime <= basicTime) {
            return basicFee;
        }
        return basicFee + (int) Math.ceil((double) (totalTime - basicTime) / duration) * durFee;
    }
}