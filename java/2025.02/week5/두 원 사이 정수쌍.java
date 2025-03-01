// 채점 결과
// 정확성: 60.0
// 합계: 60.0 / 100.0

import java.util.*;

class Solution {
    
    long r1Pow;
    long r2Pow;
    
    public long solution(int r1, int r2) {
        long answer = 0;
        
        r1Pow = r1*r1;
        r2Pow = r2*r2;
        
        int firstCount = 0;
        for(int i = r2-1; i > 0; i--) { // x좌표
            int count = binarySearchR2first(i) - binarySearchR1first(i);

            if (count == 0) break;
            firstCount += count;
        }
        //System.out.println(firstCount);
        
        int secondCount = binarySearchR2second(r2) - binarySearchR1second(r1);;

        //System.out.println(secondCount);
        
        return (2 * firstCount + secondCount + r2 - r1 + 1) * 4;
    }
    
    int binarySearchR2first(int x) {
        int start = 1;
        int end = x-1;
        int cnt = 0;

        long xPow = x*x;
        while(start <= end) {
            int mid = (start + end) / 2;

            if(xPow + mid*mid > r2Pow) {
                end = mid - 1;
            } else {
                cnt = mid;
                start = mid + 1;
            }
        }
        return cnt;
    }
    
    int binarySearchR1first(int x) {
        int start = 1;
        int end = x-1;
        int cnt = 0;

        long xPow = x*x;
        while(start <= end) {
            int mid = (start + end) / 2;

            if(xPow + mid*mid >= r1Pow) {
                end = mid - 1;
            } else {
                cnt = mid;
                start = mid + 1;
            }
        }
        return cnt;
    }
    
    int binarySearchR2second(int r2) {
        int start = 1;
        int end = r2;
        int cnt = 0;

        while(start <= end) {
            int mid = (start + end) / 2;

            if(2 * mid*mid > r2Pow) {
                end = mid - 1;
            } else {
                cnt = mid;
                start = mid + 1;
            }
        }
        return cnt;
    }
    
    int binarySearchR1second(int r1) {
        int start = 1;
        int end = r1;
        int cnt = 0;

        while(start <= end) {
            int mid = (start + end) / 2;

            if(2 * mid*mid >= r1Pow) {
                end = mid - 1;
            } else {
                cnt = mid;
                start = mid + 1;
            }
        }
        return cnt;
    }
}