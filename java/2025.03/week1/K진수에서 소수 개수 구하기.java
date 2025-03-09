// 오버플로우 발생으로 인해 틀림
// Stack 대신 String 쓰는 게 더 깔끔했을듯

import java.util.*;

class Solution {
    
    Set<Long> primeSet = new HashSet<>();
    
    public int solution(int n, int k) {
        int answer = 0;
        primeSet.add((long)2);
        
        Stack<Integer> stk = new Stack<>();
        List<Long> list = new ArrayList<>();
        
        while(n > 0) {
            int now = n % k;
            stk.push(now);
            n /= k;
        }
        
        long temp = 0;
        while(!stk.isEmpty()) {
            int now = stk.pop();
            if(now == 0 && temp != 0) {
                list.add(temp);
                temp = 0;
            } else {
                temp = temp*10 + now;
            }
        }
        if(temp != 0) list.add(temp);
        
        for(long num : list) {
            answer += checkPrime(num);
        }
        
        return answer;
    }
    public int checkPrime(long num) {
        if(num == 0) return 0;
        if(num == 1) return 0;
        if(num == 2) return 1;
        if(num % 2 == 0) return 0;
        if(primeSet.contains(num)) return 1;
        for(int i=3; i <= Math.sqrt(num); i += 2) {
            if(num % i == 0) return 0;
        }
        primeSet.add(num);
        return 1;
    }
}